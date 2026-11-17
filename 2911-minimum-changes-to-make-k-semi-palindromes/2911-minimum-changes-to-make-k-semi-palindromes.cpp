class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = INT_MAX / 2;

        // divisors[L] = proper divisors d of L with 1 <= d < L
        vector<vector<int>> divisors(n + 1);
        for (int L = 2; L <= n; L++)
            for (int d = 1; d < L; d++)
                if (L % d == 0) divisors[L].push_back(d);

        // cost[i][j]: min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int L = j - i + 1;
                int best = INF;
                for (int d : divisors[L]) {
                    int total = 0;
                    int m = L / d;  // group size
                    for (int r = 0; r < d; r++) {
                        int lo = 0, hi = m - 1;
                        while (lo < hi) {
                            if (s[i + r + lo * d] != s[i + r + hi * d]) total++;
                            lo++;
                            hi--;
                        }
                    }
                    best = min(best, total);
                }
                cost[i][j] = best;
            }
        }

        // dp[p][j]: first j chars split into p parts
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int j = 2 * p; j <= n; j++) {
                int best = INF;
                for (int i = 2 * (p - 1); i <= j - 2; i++) {
                    if (dp[p - 1][i] < INF && cost[i][j - 1] < INF) {
                        best = min(best, dp[p - 1][i] + cost[i][j - 1]);
                    }
                }
                dp[p][j] = best;
            }
        }

        return dp[k][n];
    }
};
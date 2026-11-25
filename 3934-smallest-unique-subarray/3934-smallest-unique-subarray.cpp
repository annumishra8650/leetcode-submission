

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long M1 = 1000000007LL, M2 = 998244353LL;

        // random bases to resist anti-hash tests
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        long long B1 = rng() % (M1 - 200000) + 100000;
        long long B2 = rng() % (M2 - 200000) + 100000;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0), p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * B1 + nums[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + nums[i]) % M2;
            p1[i + 1] = p1[i] * B1 % M1;
            p2[i + 1] = p2[i] * B2 % M2;
        }

        auto feasible = [&](int L) -> bool {
            vector<unsigned long long> v;
            v.reserve(n - L + 1);
            for (int i = 0; i + L <= n; i++) {
                long long a = ((h1[i + L] - h1[i] * p1[L]) % M1 + M1) % M1;
                long long b = ((h2[i + L] - h2[i] * p2[L]) % M2 + M2) % M2;
                v.push_back((unsigned long long)a << 32 | (unsigned long long)b);
            }
            sort(v.begin(), v.end());
            int m = v.size();
            for (int i = 0; i < m; i++) {
                bool samePrev = i > 0 && v[i] == v[i - 1];
                bool sameNext = i + 1 < m && v[i] == v[i + 1];
                if (!samePrev && !sameNext) return true;
            }
            return false;
        };

        int lo = 1, hi = n;  // feasible(n) is always true
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
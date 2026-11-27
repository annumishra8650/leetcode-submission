class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> bonus(n, 0);

        // Calculate free items
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }

        const int NEG = -1e9;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        // DP
        for(int i = 0; i < n; i++) {

            int price = items[i][1];
            int freeItems = bonus[i];

            vector<int> newDp = dp;

            for(int b = price; b <= budget; b++) {

                // First copy
                if(dp[b - price] != NEG) {
                    newDp[b] = max(newDp[b],
                                   dp[b - price] + 1 + freeItems);
                }

                // Additional copies
                if(newDp[b - price] != NEG) {
                    newDp[b] = max(newDp[b],
                                   newDp[b - price] + 1);
                }
            }

            dp = newDp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
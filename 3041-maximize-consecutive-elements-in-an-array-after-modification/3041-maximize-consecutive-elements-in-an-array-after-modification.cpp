class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // values up to 1e6, plus 1 for increment, plus padding
        vector<int> dp(1000003, 0);
        int ans = 1;
        for (int x : nums) {
            // Option 1: become x+1 (uses old dp[x])
            dp[x + 1] = dp[x] + 1;
            // Option 2: stay x
            dp[x] = dp[x - 1] + 1;
            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};
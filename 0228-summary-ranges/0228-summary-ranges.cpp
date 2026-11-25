
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        int i = 0;

        while (i < n) {

            int start = nums[i];

            // Find consecutive numbers
            while (i + 1 < n &&
                   (long long)nums[i + 1] - nums[i] == 1) {
                i++;
            }

            int end = nums[i];

            // Create range
            if (start == end) {
                ans.push_back(to_string(start));
            }
            else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }

            i++;
        }

        return ans;
    }
};

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;            // segment start indices, front = leftmost
        long long sumMax = 0;     // sum of prefix maxima over window [l, r]
        long long sumNums = 0;    // sum of values over window [l, r]
        long long ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            // add nums[l]
            sumNums += nums[l];
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int j = dq.front();
                int nextStart = dq.size() > 1 ? dq[1] : r + 1;
                sumMax -= (long long)nums[j] * (nextStart - j);
                dq.pop_front();
            }
            int end = dq.empty() ? r + 1 : dq.front();   // exclusive end of l's segment
            sumMax += (long long)nums[l] * (end - l);
            dq.push_front(l);

            // shrink r until cost <= k
            while (sumMax - sumNums > k) {
                sumNums -= nums[r];
                sumMax -= nums[dq.back()];
                if (dq.back() == r) dq.pop_back();
                --r;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

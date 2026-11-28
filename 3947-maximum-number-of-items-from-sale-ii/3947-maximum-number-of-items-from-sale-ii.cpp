#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n + 1, 0);
        for (auto& it : items) cnt[it[0]]++;

        vector<long long> total(n + 1, 0);
        for (int f = 1; f <= n; f++)
            for (int m = f; m <= n; m += f)
                total[f] += cnt[m];

        vector<pair<long long, long long>> arr;
        arr.reserve(n);
        for (auto& it : items)
            arr.push_back({it[1], total[it[0]] - 1});
        sort(arr.begin(), arr.end());

        long long B = budget;
        long long pmin = arr[0].first;
        long long best = B / pmin;
        long long S = 0, k = 0;

        for (auto& [p, d] : arr) {
            if (p >= 2 * pmin) break;          // no further gain possible
            long long t = min(d, (B - S) / p); // 2-value copies we can afford
            if (t <= 0) continue;
            S += t * p;
            k += t;
            best = max(best, 2 * k + (B - S) / pmin);
        }
        return (int)best;
    }
};
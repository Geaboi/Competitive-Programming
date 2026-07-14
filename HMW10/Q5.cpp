#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = queries.size();
        
        // 1. Create and sort value pairs by nums1 descending
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back({nums1[i], nums2[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        
        // 2. Prepare offline queries sorted by xi descending
        vector<vector<int>> q(m);
        for (int i = 0; i < m; ++i) {
            q[i] = {queries[i][0], queries[i][1], i};
        }
        sort(q.begin(), q.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        
        vector<int> ans(m, -1);
        // Monotonic stack stores {nums2[j], sum[j]}
        // It will be increasing in nums2 and decreasing in sum
        vector<pair<int, int>> st;
        
        int j = 0;
        for (int i = 0; i < m; ++i) {
            int xi = q[i][0], yi = q[i][1], idx = q[i][2];
            
            // Add all pairs that satisfy nums1[j] >= xi
            while (j < n && pairs[j].first >= xi) {
                int v2 = pairs[j].second;
                int sum = pairs[j].first + pairs[j].second;
                
                // If current sum is <= sum of a pair with larger or equal v2, ignore it
                while (!st.empty() && st.back().second <= sum) {
                    st.pop_back();
                }
                
                // Only add if it could potentially be a maximum (v2 is larger than current stack back)
                if (st.empty() || v2 > st.back().first) {
                    st.push_back({v2, sum});
                }
                j++;
            }
            
            // 3. Binary search on the stack for the first element where st[k].v2 >= yi
            auto it = lower_bound(st.begin(), st.end(), make_pair(yi, 0), 
                                 [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });
            
            if (it != st.end()) {
                ans[idx] = it->second;
            }
        }
        
        return ans;
    }
};
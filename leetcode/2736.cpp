class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size(), m = queries.size();
        
        vector<pair<int, int>> A;
        for(auto i = 0; i < n; ++i)
            A.push_back({nums1[i], nums2[i]});
        sort(A.begin(), A.end());
        
        vector<vector<int>> Q;
        for(auto i = 0; i < m; ++i)
            Q.push_back({queries[i][0], queries[i][1], i});
        sort(Q.begin(), Q.end());
        
        vector<int> ret(m);
        vector<pair<int, int>> mono;
        while(!Q.empty()) {
            auto qx = Q.back()[0], qy = Q.back()[1], qi = Q.back()[2];
            Q.pop_back();
            while(!A.empty() && A.back().first >= qx) {
                auto [x, y] = A.back();
                A.pop_back();
                while(!mono.empty() && mono.back().second <= x + y)
                    mono.pop_back();
                if(mono.empty() || mono.back().first < y)
                    mono.push_back({y, x + y});
            }
            auto p = lower_bound(mono.begin(), mono.end(), make_pair(qy, 0));
            ret[qi] = p == mono.end() ? -1 : p->second;
        }
        
        return ret;
    }
};

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        set<int> r, c;
        long long ret = 0;
        reverse(queries.begin(), queries.end());
        for(auto& q: queries) {
            auto& rr = q[0] ? c : r;
            auto& cc = q[0] ? r : c;
            ret += rr.count(q[1]) ? 0 : q[2] * (n - (int) cc.size());
            rr.insert(q[1]);
        }
        
        return ret;
    }
};

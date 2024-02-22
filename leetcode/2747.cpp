class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int> ret(queries.size());
        vector<pair<int, int>> Q;
        for(auto i = 0; i < queries.size(); ++i)
            Q.push_back({queries[i], i});
        sort(Q.begin(), Q.end(), greater<pair<int, int>>());
        
        sort(logs.begin(), logs.end(), [](auto& l, auto& r) { return l[1] > r[1]; });
        
        map<int, int> ids;
        deque<vector<int>> DQ;
        while(!Q.empty()) {
            while(!logs.empty() && logs.back()[1] < Q.back().first - x)
                logs.pop_back();
            while(!logs.empty() && logs.back()[1] <= Q.back().first) {
                DQ.push_back(logs.back());
                ids[logs.back()[0]]++;
                logs.pop_back();
            }
            while(!DQ.empty() && DQ.front()[1] < Q.back().first - x) {
                if(--ids[DQ.front()[0]] == 0)
                    ids.erase(DQ.front()[0]);
                DQ.pop_front();
            }
            ret[Q.back().second] = n - (int)ids.size();
            Q.pop_back();
        }
        return ret;
    }
};

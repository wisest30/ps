class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for(auto i = 1; i < n; ++i) {
            g[i].push_back(parent[i]);
            g[parent[i]].push_back(i);
        }
        
        unordered_map<int, long long> m;
        long long ret = 0;
        function<void(int, int, int)> dfs = [&](auto cur, auto prev, auto x) {
            ret += m[x];
            for(auto i = 0; i < 26; ++i)
                ret += m[x ^ (1 << i)];
            m[x]++;
            for(auto nxt : g[cur]) {
                if(nxt == prev) continue;
                dfs(nxt, cur, x ^ (1 << (s[nxt] - 'a')));
            }
        };
        
        dfs(0, -1, 0);
        return ret;
    }
};

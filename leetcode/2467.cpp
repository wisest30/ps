class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<int> par(n, -1);
        function<void(int, int)> dfs = [&](int cur, int prev) {
            par[cur] = prev;
            for(auto nxt : g[cur])
                if(nxt != prev)
                    dfs(nxt, cur);
        };
        dfs(0, -1);

        queue<array<int, 3>> q0, q1;
        q0.push({0, 0, 0});

        auto ret = -INT_MAX;
        while(!q0.empty()) {
            while(!q0.empty()) {
                auto cur = q0.front()[0];
                auto prev = q0.front()[1];
                auto val = q0.front()[2];
                q0.pop();
                
                val += cur == bob ? amount[cur] / 2 : amount[cur];
                if(cur != 0 && g[cur].size() == 1)
                    ret = max(ret, val);

                for(auto nxt : g[cur]) {
                    if(nxt == prev) continue;
                    q1.push({nxt, cur, val});
                }
            }
            
            if(bob != -1) {
                amount[bob] = 0;
                bob = par[bob];
            }

            swap(q0, q1);
        }
        
        return ret;
    }
};

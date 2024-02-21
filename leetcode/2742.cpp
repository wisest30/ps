class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        constexpr int MAX_TIME = 500;
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(2 * MAX_TIME + 1, INT_MAX));
        dp[0][MAX_TIME] = 0;
        for(auto i = 0; i < n; ++i) {
            for(auto j = 0; j < 2 * MAX_TIME + 1; ++j) {
                if(dp[i][j] == INT_MAX) continue;
                if(j) dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]);
                if(j + time[i] < 2 * MAX_TIME + 1) dp[i+1][j + time[i]] = min(dp[i+1][j + time[i]], dp[i][j] + cost[i]);
            }
        }
        auto ret = *min_element(dp[n].begin() + MAX_TIME, dp[n].end());
        return ret;
    }
};

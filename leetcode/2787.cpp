constexpr int MOD = 1e9 +7;
class Solution {
public:
    int numberOfWays(long long n, long long x) {
        vector<long long> P(n+1, 1);
        for(auto i = 1; i <= n; ++i)
            for(auto j = 0; j < x; ++j)
                P[i] = P[i] * i;
        
        vector<vector<long long>> dp(n+1, vector<long long>(n+1));
        dp[0][0] = 1;
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < n; ++j)
                for(auto k = j+1; k <= n && i+P[k] <= n; ++k)
                    dp[i+P[k]][k] = (dp[i+P[k]][k] + dp[i][j]) % MOD;

        long long ret = 0;
        for(auto i = 0; i <= n; ++i)
            ret = (ret + dp[n][i]) % MOD;
        return ret;
    }
};

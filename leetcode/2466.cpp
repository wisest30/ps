constexpr int MOD = 1000000007;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1);
        dp[0] = 1;
        for(auto i = 1; i <= high; ++i) {
            if(i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if(i >= one)
                dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
        
        long long ret = 0;
        for(auto i = low; i <= high; ++i)
            ret = (ret + dp[i]) % MOD;
        return ret;
    }
};

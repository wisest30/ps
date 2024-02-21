class Solution {
public:
    int specialPerm(vector<int>& nums) {
        constexpr int MOD = 1e9 + 7;
        int n = nums.size();
        vector<vector<long long>> dp(1 << n, vector<long long>(n+1));
        for(auto i = 0; i < n; ++i)
            dp[1 << i][i] = 1;
        for(auto subset = 1; subset < (1 << n); ++subset) {
            for(auto i = 0; i < n; ++i) {
                if(subset & (1 << i))
                    continue;
                for(auto j = 0; j < n; ++j) {
                    if(!(subset & (1 << j))) continue;
                    if(max(nums[i], nums[j]) % min(nums[i], nums[j])) continue;
                    dp[subset | (1 << i)][i] += dp[subset][j];
                    dp[subset | (1 << i)][i] %= MOD;
                }
            }
        }
        
        return accumulate(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end(), 0ll) % MOD;
    }
};

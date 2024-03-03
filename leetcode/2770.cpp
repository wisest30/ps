class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(auto i = 1; i < n; ++i)
            for(auto j = 0; j < i; ++j)
                if(dp[j] != -1 && abs(nums[i] - nums[j]) <= target)
                    dp[i] = max(dp[i], dp[j] + 1);
        return dp[n-1];
    }
};

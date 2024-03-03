class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ret = 1;
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for(auto i = 1; i < n; ++i) {
            for(auto j = 0; j < 2; ++j) {
                auto& nums = j == 0 ? nums1 : nums2;
                if(nums[i] >= nums1[i-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][0] + 1);
                if(nums[i] >= nums2[i-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][1] + 1);
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};

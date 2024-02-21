class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = INT_MAX;
        for(auto i = 0; i + 1 < nums.size(); ++i)
            ret = min(ret, nums[i+1] - nums[i]);
        return ret;
    }
};

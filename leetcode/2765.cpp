class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(), ret = -1;
        for(auto i = 0; i < n; ++i) {
            for(auto j = i + 1; j < n; ++j) {
                if(nums[j] - nums[i] != (j - i) % 2)
                    break;
                ret = max(ret, j + 1 - i);
            }
        }
        return ret;
    }
};

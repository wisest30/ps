class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ret = 0;
        for(auto i = 0; i < nums.size(); ++i) {
            if(nums[i] % 2 || nums[i] > threshold) continue;
            int j = i + 1;
            while(j < nums.size() && nums[j] <= threshold && nums[j] % 2 != nums[j-1] % 2)
                ++j;
            ret = max(ret, j - i);
        }
        return ret;
    }
};

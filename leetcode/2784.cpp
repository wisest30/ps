class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(auto i = 0; i + 1 < nums.size(); ++i)
            if(nums[i] != i + 1)
                return false;
        return nums.back() + 1 == nums.size();
    }
};

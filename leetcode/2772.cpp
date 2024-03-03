class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> delta(n+1);
        long long cur = 0;
        for(auto i = 0; i < n; ++i) {
            cur += delta[i];
            if(nums[i] + cur < 0)
                return false;
            if(i + k > n) {
                if(nums[i] + cur != 0)
                    return false;
            } else {
                delta[i+1] -= nums[i] + cur;
                delta[i+k] += nums[i] + cur;
            }
        }
        return true;
    }
};

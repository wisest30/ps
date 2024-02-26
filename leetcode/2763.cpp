class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ret = 0, n = nums.size();
        for(auto i = 0; i < n; ++i) {
            vector<bool> A(n+2);
            A[nums[i]] = true;
            for(auto j = i+1, cur = 0; j < n; ++j) {
                cur += A[nums[j]] ? 0 : 1 - A[nums[j] + 1] - A[nums[j] - 1];
                A[nums[j]] = true, ret += cur;
            }
        }
        return ret;
    }
};

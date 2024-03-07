class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        long long m[2] = {nums[0], nums[0]};
        m[(nums[0] % 2) ^ 1] -= x;
        for(auto i = 1; i < n; ++i) {
            auto p = nums[i] % 2;
            m[p] += nums[i];
            m[p] = max(m[p], m[p ^ 1] + nums[i] - x);
        }
        
        return max(m[0], m[1]);
    }
};

class Solution {
public:
    long long minCost(vector<int>& nums, long long x) {
        long long ret = INT64_MAX;
        long long n = nums.size();
        auto A = nums;
        for(long long count = 0; count < n; ++count) {
            long long candi = accumulate(A.begin(), A.end(), 0ll);
            candi += count * x;
            ret = min(ret, candi);
            for(auto i = 0; i < n; ++i) {
                auto j = (i - 1 - count + n) % n;
                A[i] = min(A[i], nums[j]);
            }
        }
        
        return ret;
    }
};

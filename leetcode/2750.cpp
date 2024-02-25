class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        constexpr int MOD = 1e9 + 7;
        vector<long long> A{0};
        for(auto x : nums)
            if(x) A.push_back(0);
            else A.back()++;
        
        if(A.size() < 3)
            return A.size() - 1;
        
        long long ret = 1;
        for(auto i = 1; i + 1 < A.size(); ++i)
            ret = ret * (A[i] + 1) % MOD;
        return ret;
    }
};

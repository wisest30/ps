class Solution {
public:
    int sumDistance(vector<int>& nums, string s, long long d) {
        constexpr long long MOD = 1e9 + 7;
        
        int n = nums.size();
        vector<long long> A(n);
        for(auto i = 0; i < n; ++i)
            A[i] = nums[i] + (s[i] == 'L' ? -d : d);
        sort(A.begin(), A.end());
 
        long long ret = 0;
        for(auto i = 0; i < n; ++i)
            ret = (ret + (i - (n - i - 1)) * A[i] % MOD + MOD) % MOD;
        
        return ret;
    }
};

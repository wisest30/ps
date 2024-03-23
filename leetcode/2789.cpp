class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> A(nums.begin(), nums.end());
        
        while(A.size() > 1) {
            if(A[A.size() - 2] <= A.back())
                A[A.size() - 2] += A.back();
            A.pop_back();
        }
        
        return A[0];
    }
};

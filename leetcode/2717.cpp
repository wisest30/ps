class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int a = find(nums.begin(), nums.end(), 1) - nums.begin();
        int b = find(nums.begin(), nums.end(), n) - nums.begin();
        return a + n - 1 - b - (a > b);
    }
};

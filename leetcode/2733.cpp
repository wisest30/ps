class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if(s.size() <= 2)
            return -1;
        return *next(s.begin());
    }
};

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ret = 0;
        for(auto i = 0; i < nums.size(); ++i)
            for(auto j = i + 1; j < nums.size(); ++j)
                ret += __gcd(to_string(nums[i])[0] - '0', to_string(nums[j]).back() - '0') == 1;
        return ret;
    }
};

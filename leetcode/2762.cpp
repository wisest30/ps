class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ret = 0;
        multiset<int> s;
        for(auto i = 0, j = 0; i < nums.size(); ++i) {
            while(j < nums.size() && (s.empty() || abs(*s.begin() - nums[j]) <= 2 && abs(*s.rbegin() - nums[j]) <= 2)) {
                s.insert(nums[j++]);
                ret += s.size();
            }
            s.erase(s.find(nums[i]));
        }
        return ret;
    }
};

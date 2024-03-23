class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt = set<int>(nums.begin(), nums.end()).size();
        map<int, int> m;
        long long ret = 0, n = nums.size();
        for(long long i = 0, j = 0; i < n; ++i) {
            while(j < n && m.size() < cnt)
                m[nums[j++]]++;
            if(m.size() < cnt)
                break;
            ret += n - j + 1;
            m[nums[i]]--;
            if(!m[nums[i]])
                m.erase(nums[i]);
        }
        return ret;
    }
};

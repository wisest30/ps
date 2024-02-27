class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s(nums.begin(), nums.end());
        for(auto i = 0; i < moveFrom.size(); ++i) {
            if(s.count(moveFrom[i])) {
                s.erase(moveFrom[i]);
                s.insert(moveTo[i]);
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        deque<int> q(nums.begin(), nums.end());
        set<double> s;
        while(!q.empty()) {
            s.insert(((double)q.front() + q.back()) / 2);
            q.pop_front();
            q.pop_back();
        }
        return s.size();
    }
};

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<pair<int, int>> A;
        set<int> s;
        for(auto i = 0; i < r; ++i) {
            int x = 0;
            for(auto j = 0; j < c; ++j) if(grid[i][j]) x |= 1 << j;
            if(!s.count(x)) {
                A.push_back({x, i});
                s.insert(x);
            }
            if(!x) return {i};
        }
        
        for(auto i = 0; i < A.size(); ++i)
            for(auto j = i+1; j < A.size(); ++j)
                if(!(A[i].first & A[j].first))
                    return {A[i].second, A[j].second};
        
        return {};
    }
};

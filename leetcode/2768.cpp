class Solution {
public:
    vector<long long> countBlackBlocks(long long m, long long n, vector<vector<int>>& coords) {
        map<pair<int, int>, long long> mp;
        for(auto& c : coords)
            for(auto i = 0; i <= 1; ++i)
                for(auto j = 0; j <= 1; ++j)
                    if(0 < c[0] + i && c[0] + i < m && 0 < c[1] + j && c[1] + j < n)
                        mp[make_pair(c[0] + i, c[1] + j)]++;
        
        vector<long long> ret(5);
        for(auto& p : mp)
            ret[p.second]++;
        ret[0] = (m - 1) * (n - 1) - ret[1] - ret[2] - ret[3] - ret[4];
        return ret;
    }
};

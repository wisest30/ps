class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        auto dp = vector<vector<vector<int>>>(26, vector<vector<int>>(26, vector<int>(n, INT_MAX)));
        dp[words[0].front() - 'a'][words[0].back() - 'a'][0] = words[0].size();
        for(auto i = 0; i < n - 1; ++i) {
            for(auto s = 0; s < 26; ++s) {
                for(auto e = 0; e < 26; ++e) {
                    if(dp[s][e][i] == INT_MAX) continue;
                    auto l = words[i+1].front() - 'a';
                    auto r = words[i+1].back() - 'a';
                    int len = words[i+1].size();
                    dp[l][e][i+1] = min(dp[l][e][i+1], dp[s][e][i] + len - (r == s));
                    dp[s][r][i+1] = min(dp[s][r][i+1], dp[s][e][i] + len - (e == l));
                }
            }
        }
        int ret = INT_MAX;
        for(auto i = 0; i < 26; ++i)
            for(auto j = 0; j < 26; ++j)
                ret = min(ret, dp[i][j][n-1]);
        return ret;
    }
};

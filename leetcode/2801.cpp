constexpr long long MOD = 1e9 +7;
class Solution {
    vector<vector<vector<long long>>> dp;
public:
    bool is_stepping(string& s) {
        for(auto i = 1; i < s.size(); ++i)
            if(abs(s[i] - s[i-1]) != 1)
                return false;
        return true;
    }
    
    long long recur(const string& s, int prev, int idx, bool less) {
        if(idx == s.size())
            return 1;
        auto& ret = dp[prev][idx][less];
        if(ret != -1)
            return ret;
        
        ret = 0;
        if(idx == 0) {
            for(auto c = 1; c <= s[idx] - '0'; ++c)
                ret = (ret + recur(s, c, idx + 1, c < s[idx] - '0')) % MOD;
        } else {            
            for(auto c = prev - 1; c <= prev + 1; ++c) {
                if(c < 0 || c > 9 || c == prev || !less && c > s[idx] - '0')
                    continue;
                ret = (ret + recur(s, c, idx + 1, less || (c < s[idx] - '0'))) % MOD;
            }
        }
        return ret;
    }
    
    long long h(const string& s) {
        dp = vector<vector<vector<long long>>>(10, vector<vector<long long>>(s.size(), vector<long long>(2, -1)));
        return recur(s, 0, 0, false);
    }

    long long f(const string& s) {
        auto ret = h(s);
        for(auto len = 1; len < s.size(); ++len)
            ret = (ret + h(string(len, '9'))) % MOD;
        return ret;
    }
    int countSteppingNumbers(string low, string high) {
        return (f(high) - f(low) + is_stepping(low) + MOD) % MOD;
    }
};

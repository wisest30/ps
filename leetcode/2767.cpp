class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(auto i = 1; i <= n; ++i) {
            for(auto len = 1; i - len >= 0; ++len) {
                if(s[i-len] == '0')
                    continue;

                int num = 0;
                for(auto k = 0; k < len; ++k)
                    num = num * 2 + s[i-len+k] - '0';
                while(num % 5 == 0)
                    num /= 5;
                if(num == 1 && dp[i-len] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-len] + 1);
            }
        }
        
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};

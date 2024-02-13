class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int p = 0, pp = 0, ret = 0;
        for(auto i = 1; i < s.size(); ++i) if(s[i-1] == s[i]) {
            ret = max(ret, i - pp);
            pp = p;
            p = i;
        }
        return max(ret, (int)s.size() - pp);
    }
};

class Solution {
public:
    bool is_match(string s, string t) {
        reverse(s.begin(), s.end());
        return s == t;
    }
    
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ret = 0;
        for(auto i = 0; i < words.size(); ++i)
            for(auto j = i + 1; j < words.size(); ++j)
                ret += is_match(words[i], words[j]);
        return ret;
    }
};

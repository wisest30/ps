class Solution {
public:
    string smallestString(string s) {
        if(count(s.begin(), s.end(), 'a') == s.size()) {
            s[s.size() - 1] = 'z';
            return s;
        }
        
        int p = 0;
        while(p < s.size() && s[p] == 'a')
            ++p;
        int q = p;
        while(q < s.size() && s[q] != 'a')
            ++q;
        for(auto i = p; i < q; ++i)
            s[i] -= 1;
        return s;
    }
};

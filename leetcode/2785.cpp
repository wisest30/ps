class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string sortVowels(string s) {
        string v;
        for(auto c : s)
            if(is_vowel(c))
                v.push_back(c);
        sort(v.begin(), v.end(), greater<char>());
        
        for(auto& c : s) {
            if(is_vowel(c)) {
                c = v.back();
                v.pop_back();
            }
        }
        
        return s;
    }
};

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ret;
        for(auto& word : words) {
            stringstream ss(word);
            string token;
            while(getline(ss, token, separator))
                if(!token.empty())
                    ret.push_back(token);
        }
        
        return ret;
    }
};

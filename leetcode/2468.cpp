class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        for(auto len = 1; len <= 5; ++len) {
            int i = 1, p = 0;
            vector<string> ret;
            while(p < n) {
                string s;
                int suffix_len = 3 + len + to_string(i).size();
                if(suffix_len >= limit) {
                    ret.clear();
                    break;
                }
                while(p < n && s.size() + suffix_len < limit) {
                    s.push_back(message[p]);
                    ++p;
                }
                s.push_back('<');
                s += to_string(i);
                s.push_back('/');
                s += string(len, '?');
                s.push_back('>');
                ret.push_back(s);
                ++i;
            }
            
            if(ret.empty())
                continue;
            if(to_string(ret.size()).size() != len)
                continue;
            
            auto count = to_string(i - 1);
            for(auto& s : ret) {
                for(auto i = 0; i < count.size(); ++i) {
                    s[s.size() - len - 1 + i] = count[i];
                }
            }
            
            return ret;
        }
        
        return {};
    }
};

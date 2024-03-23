class Solution {
public:
    bool h(string& a, string& b, int len) {
        for(auto i = 0; i < len; ++i)
            if(a[(int)a.size() + i - len] != b[i])
                return false;
        return true;
    }
    
    string f(string a, string b, string c) {
        string ret = a;
        for(auto s : {b, c}) {
            if(ret.find(s) != string::npos)
                continue;
            for(auto len = min(ret.size(), s.size()); len >= 0; --len) {
                if(h(ret, s, len)) {
                    ret += s.substr(len);
                    break;
                }
            }
        }

        return ret;
    }
    
    string minimumString(string a, string b, string c) {
        vector<string> candi;
        candi.push_back(f(a, b, c));
        candi.push_back(f(a, c, b));
        candi.push_back(f(b, a, c));
        candi.push_back(f(b, c, a));
        candi.push_back(f(c, a, b));
        candi.push_back(f(c, b, a));
        sort(candi.begin(), candi.end(), [](auto& l, auto& r) {
            if(l.size() == r.size())
                return l < r;
            return l.size() < r.size();
        });
        return candi[0];
    }
};

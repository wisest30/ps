class Solution {
public:
    int maxIncreasingGroups(vector<int>& A) {
        sort(A.begin(), A.end());

        long long r = 0, ret = 1;
        for(auto a : A) {
            r += a;
            if(r >= ret)
                r -= ret++;            
        }

        ret--;
        return ret;
    }
};

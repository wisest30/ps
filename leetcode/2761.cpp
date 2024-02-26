class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for(auto i = 2; i <= n; ++i) {
            if(!isPrime[i]) continue;
            for(auto j = i + i; j <= n; j += i)
                isPrime[j] = false;
        }
               
        vector<vector<int>> ret;
        for(auto i = 2, j = n - 2; i < n && i <= j; ++i, --j)
            if(isPrime[i] && isPrime[j])
                ret.push_back({i, j});
        
        return ret;
    }
};

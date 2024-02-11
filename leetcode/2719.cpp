static constexpr int MOD = 1e9 + 7;
static long long dp[2][30][401];
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        auto a = count2(num1, min_sum, max_sum);
        auto b = count2(num2, min_sum, max_sum);
        int su = 0;
        for(auto& c : num1)
            su += c - '0';
        return (b - a + (min_sum <= su && su <= max_sum) + MOD) % MOD;
    }
    
    long long count2(string num, int min_sum, int max_sum) {
        return (count3(num, max_sum) - count3(num, min_sum - 1) + MOD) % MOD;
    }
    
    long long count3(string num, int max_sum) {
        long long ret = 0;
        for(auto i = 1; i < num.size(); ++i)
            ret += count4(i, string(i, '9'), max_sum);
        ret += count4(num.size(), num, max_sum);
        return ret % MOD;
    }
    
    long long count4(int length, string num, int max_sum) {
        memset(dp, -1, sizeof(dp));
        function<long long(bool, int, int)> recur = [&](bool less, int i, int su) {
            if(i == num.size())
                return (long long)(su <= max_sum);
            
            auto& ret = dp[less][i][su];
            if(ret != -1) return ret;
            ret = 0;
            for(auto j = 0; j < 10; ++j) {
                if(!i && !j) continue;
                if(!less && j + '0' > num[i]) break;
                ret += recur(less || j + '0' < num[i], i + 1, su + j);
                ret %= MOD;
            }
            return ret;
        };
        
        return recur(false, 0, 0);
    }
};

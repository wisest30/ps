class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for(auto ret = 1; ret < 100; ++ret) {
            num1 -= num2;
            if(num1 < 0)
                return -1;
            if(__builtin_popcountll(num1) <= ret && ret <= num1)
                return ret;
        }
        return -1;
    }
};

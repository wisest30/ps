class Solution {
public:
    int distanceTraveled(int m, int a) {
        auto ret = 0;
        while(true)
            if(m >= 5 && a) ret += 50, m -= 4, a--;
            else return ret + m * 10;
    }
};

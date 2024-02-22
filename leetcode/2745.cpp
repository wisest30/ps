class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x > y) swap(x, y);
        y = min(y, x + 1);
        return (x + y + z) * 2;
    }
};

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xx = abs(x - z);
        int yy = abs(y - z);

        if(xx > yy) return 2;
        else if(xx < yy) return 1;
        return 0; 
    }
};
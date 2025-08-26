class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {

        int n = rectangles.size();
        vector<int> length(n);

        int maxi = 0;
        for(int i=0;i<n;i++){
            length[i] = min(rectangles[i][0], rectangles[i][1]);
            maxi = max(maxi, length[i]);
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(maxi == length[i]) count++;
        }

        return count;
    }
};
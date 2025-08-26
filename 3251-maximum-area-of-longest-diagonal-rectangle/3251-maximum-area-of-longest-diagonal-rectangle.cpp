class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        int maximumArea = 0;
        float maxiDiag = 0;

        for(int i=0;i<n;i++){

            int area = dimensions[i][0] * dimensions[i][1];

            int v = (dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]);
            float diag = sqrt(v);

            if(diag == maxiDiag){
                maxiDiag = diag;
                if(area > maximumArea) maximumArea = area;
            }
            else if(diag > maxiDiag){
                maxiDiag = diag;
                maximumArea = area;
            }

        }
        return maximumArea;
    }
};
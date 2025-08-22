class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int startflag = 0;

        int startrow, startcol, endcol, endrow;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && startflag == 0){
                    startrow = i;
                    startcol = j;
                    endrow = i;
                    endcol = j;
                    startflag = 1;
                }
                else if(grid[i][j] == 1 && startflag){
                    endrow = i;
                    if(j < startcol) startcol = j;
                    else if( j > endcol ) endcol = j;
                }
            }
            
        }
        int area = (endrow - startrow + 1) * (endcol - startcol + 1);

        return area;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0;i<row;i++){
            int l = 0, r = col - 1;
            int mid;

            while(l <= r){
                mid = (l+r)/2;

                if(matrix[i][mid] == target) return true;

                else if( matrix[i][mid] > target){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};
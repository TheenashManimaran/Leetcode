class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix(m+1, vector<int> (n+1, 0));

        // storing prefix sum 2d array from given matrix
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                prefix[i+1][j+1] = mat[i][j] + prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
            }
        }
        // just printing
        /*
        for(int i=0;i<m+1;i++){
            for(int j = 0;j<n+1;j++){
                cout<<prefix[i][j]<<" ";
            }cout<<endl;
        }
        */
        // 2d array ans
        vector<vector<int>> ans(m, vector<int>(n));

        // main algo
        for(int i=1,r = 0;i<m+1;i++,r++){
            for(int j = 1,c = 0;j<n+1;j++,c++){
                int r1 = max(1, i - k);
                int c1 = max(1, j - k);
                int r2 = min(m, i+k);
                int c2 = min(n, j+k);

                ans[r][c] = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
            }
        }

        return ans;

        return {{}};


    }
};
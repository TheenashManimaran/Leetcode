class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int upright = 1;
        int curi = 0, curj = 0;

        vector<int> ans;
        int cur;

        while(curi < n && curj< m){
            cur = mat[curi][curj];
            ans.push_back(cur);
            cout<<cur<<endl;
            cout<<curi<<" "<<curj<<endl;
            if(curi == m-1 && curj == n-1) break;

            if(upright){
                int r = curi - 1, c = curj + 1;
                if(r < 0 && c > m-1){
                    curi = curi + 1; 
                    curj = curj;
                    upright = 0;
                }
                else if(c > m-1){
                    curi = curi+1;
                    curj = curj;
                    upright = 0;
                }
                else if(r < 0){
                    curi = curi;
                    curj = curj + 1;
                    upright = 0;
                }
                else{
                    curi = r;
                    curj = c;
                }
            }
            else{
                int r = curi + 1;
                int c = curj - 1;
                if(r > n-1 && c < 0){
                    curi = curi;
                    curj = curj + 1;
                    upright = 1;
                }
                else if(c < 0) {
                    curi = curi + 1;
                    curj = curj;
                    upright = 1;
                }
                else if(r > n-1){
                    curi = curi;
                    curj = curj + 1;
                    upright = 1;
                }
                else{
                    curi = r;
                    curj = c;
                }
            }
        }
        return ans;
    }
};
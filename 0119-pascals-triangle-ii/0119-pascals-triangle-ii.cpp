class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>pascal;
        pascal = {{1}};
        vector<int>prev = {1};
        vector<int> temp;
        if (rowIndex == 0) return prev;
        else{
            for (int i=1;i<=rowIndex;i++){
            temp = {};
            for(int j=0;j<=i;j++){
                if (j==0 or j==i){
                    temp.push_back(1);
                }
                else{
                    int ans = prev[j-1] + prev[j];
                    temp.push_back(ans);
                }
            }
            prev = temp;
            pascal.push_back(prev);
        }
        return temp;
        }
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});

        for(int i=1;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<i+1;j++){
                if(j == 0){
                    temp.push_back(1);
                }
                else if(j == i){
                    temp.push_back(1);
                }
                else {
                    temp.push_back(ans.back()[j-1] + ans.back()[j]);
                }
                
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
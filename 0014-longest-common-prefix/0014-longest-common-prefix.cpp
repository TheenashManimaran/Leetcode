class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        // cout<<prefix<<endl;
        for(int i=1;i<strs.size();i++){
            string cur = "";
            for(int j = 0;j<strs[i].size();j++){
                if(prefix[j] == strs[i][j]){
                    cur += prefix[j];
                }
                else break;
            }
            // cout<<cur<<endl;
            prefix = cur;
        }

        return prefix;
    }
};
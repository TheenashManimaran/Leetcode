class Solution {
public:
    string largestEven(string s) {
        int n = s.size();

        int lastInd = -1;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '2'){
                lastInd = i;
                break;
            }
        }
        string str = "";
        for(int i=0;i<=lastInd;i++){
            str += s[i];
        }

        return str;
    }
};
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        string s = "", res = "";
        for(int i=0;i<num.size()-2;i++){
            int j = i+1, k = i+2;

            if(num[i] == num[j] && num[j] == num[k]){
                s += num[i];
                s += num[j]; 
                s += num[k];
                res = max(res, s);
                s = "";
            }
        }
        return res;
    }
};
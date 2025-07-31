class Solution {
public:

    string rle(string s){
        string ans = "";

        char cur = s[0];
        int c = 1;
        for(int i=1;i<s.size();i++){
            if(cur == s[i]){
                c++;

            }
            else{
                ans += (48 + c);
                ans += cur;
                cur = s[i];
                c = 1;
            }
        }
        if(cur >= 1){
            ans += (48 + c);
            ans += cur;
        }
        return ans;
    }

    string countAndSay(int n) {
        string s = "1";
        n--;
        while(n--){
            s = rle(s);
        }
        return s;
    }
};
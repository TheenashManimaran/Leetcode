class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1, b = n-1;

        int flag;
        while(a <= b){
            flag = 1;
            string sa  = to_string(a);
            string sb = to_string(b);
            for(int i=0;i<sa.size();i++){
                if(sa[i] == '0') {flag = 0; break;}
            }
            for(int i=0;i<sb.size();i++){
                if(sb[i] == '0') {flag = 0; break;}
            }
            if(flag) break;
            a++;
            b--;
        }
        return {a,b};
    }
};
class Solution {
public:
    int appendCharacters(string s, string t) {
        int si = 0, ti = 0;

        for(int i=0;i<s.size();i++){
            si = i;
            while(s[si] == t[ti] && ti < t.size()){ 
                si++;
                ti++;
                i = si;
            }
        }
        cout<<ti<<endl;
        if(ti < t.size()){
            return t.size() - ti;
        }
        else return 0;
    }
};
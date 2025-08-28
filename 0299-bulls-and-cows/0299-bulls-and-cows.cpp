class Solution {
public:
    string getHint(string s, string g) {
        int n = s.size();


        // s = secret and g = guess
        int cow = 0, bull = 0;
        map<char, int> mapp;
        for(int i=0;i<n;i++){
            mapp[g[i]]++;
        }
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == g[i]){
                bull++;
                mapp[g[i]]--;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i] != g[i]){
                if(mapp[s[i]] > 0){
                    cow++;
                    mapp[s[i]]--;
                }
            }
        }
        ans += to_string(bull) + 'A';
        ans += to_string(cow) + 'B';
        
        return ans;
    }
};
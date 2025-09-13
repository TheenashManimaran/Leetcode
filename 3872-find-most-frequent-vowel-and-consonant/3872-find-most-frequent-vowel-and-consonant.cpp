class Solution {
public:
    int maxFreqSum(string s) {
        int freqSum = 0;

        map<char,int> vowel;
        map<char,int> conso;

        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'u' ||s[i] == 'o' || s[i] == 'i' || s[i] == 'e'){
                vowel[s[i]]++;
            }
            else conso[s[i]]++;
        }
        int maxi = 0;
        for(auto &[x,y] : vowel){
            maxi = max(maxi, y);
        }
        freqSum += maxi;
        maxi = 0;
        for(auto &[x,y] : conso){
            maxi = max(maxi, y);
        }

        freqSum += maxi;

        return freqSum;
    }
};
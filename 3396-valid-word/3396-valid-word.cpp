class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        int vowel = 0,cons = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            if(word[i] >= 65 && word[i]<=90){
                word[i] = word[i] + 32;
            }
            if(word[i] >= 97 && word[i] <= 122){
                count++;
                char c = word[i];
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) vowel++;
                else cons++;
            }
            else if(word[i] >= 48 && word[i] <= 57){
                count++;
            }
            else{
                return false;
            }

        }
        if(vowel > 0 && cons > 0 && count > 2) return true;
        return false;

    }
};
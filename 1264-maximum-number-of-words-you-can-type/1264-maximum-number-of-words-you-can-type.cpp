class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int flag = 1;
        map<char,int> mapp;
        for(int i=0;i<brokenLetters.size();i++){
            mapp[brokenLetters[i]]++;
        }
        int count = 0;
        for(int i=0;i<text.size();i++){
            if(mapp[text[i]] == 1){
                flag = 0;
            }
            if(text[i] == ' '){
                if(flag == 0) flag = 1;
                else {
                    count++;
                    flag = 1;
                }
            }

        }

        if(flag == 1) count++;

        return count;
    }
};
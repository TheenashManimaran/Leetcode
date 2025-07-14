class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        bool ans = true;
        char char1 = sentence[0];
        char charlast = sentence[n-1];

        int spaceflag = 0;
        char cur = sentence[0];
        for(int i=0;i<n;i++){
            if(sentence[i] == ' '){
                if(cur != sentence[i+1]){
                    ans = false;
                    break;
                }
                continue;
            }
            cur = sentence[i];
            
        }

        if(ans == true && char1 == charlast) ans = true;
        else ans = false;
        return ans;
    }
};
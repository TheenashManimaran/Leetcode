class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int t = target.size(); // target size
        map<int,int> mapp;

        for(int i:  target){
            mapp[i]++;
        }

        vector<string> ans;
        int count = 0;
        for(int i=1;i<=n;i++){
            if(count == t){
                break;
            }
            if(mapp.count(i)){
                ans.push_back("Push");
                count++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};
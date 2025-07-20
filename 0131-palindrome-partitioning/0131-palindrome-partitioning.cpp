class Solution {
public:

    bool palindrome(int left, int right, string s){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++; right--;

        }
        return true;
    }

    void func(int ind, string s, vector<string> &ds, vector<vector<string>> &ans, int n){

        // base case:
        if(ind == n){
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i<n; i++){

            if( palindrome(ind,i,s) ){

                string part = "";
                for(int j=ind;j<=i;j++) part += s[j];

                ds.push_back(part);
                func(i + 1, s, ds, ans, n);
                ds.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = s.size();

        func(0,s,ds,ans,n);
        
        return ans;
    }
};
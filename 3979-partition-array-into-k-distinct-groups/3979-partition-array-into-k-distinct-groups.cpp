class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false; // groups cannot be formed

        

        int groups = n / k;
        map<int,int> mapp;
        for(int i=0;i<n;i++){
            mapp[nums[i]]++;
        } 

        for(auto &[x,y] : mapp){
            if(y > groups) return false;
        }
        return true;
    }
};
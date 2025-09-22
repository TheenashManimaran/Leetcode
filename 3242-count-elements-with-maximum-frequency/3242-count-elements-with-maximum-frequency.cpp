class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mapp;

        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
            maxi = max(maxi, mapp[nums[i]]);
        }


        int count = 0;
        for(auto it: mapp){
            if(it.second == maxi){
                count++;
            }
        }
        return count * maxi;
    }
};
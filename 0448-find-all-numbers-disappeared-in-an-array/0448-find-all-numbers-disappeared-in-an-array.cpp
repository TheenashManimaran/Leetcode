class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,int> mapp;

        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
        }

        vector<int> ans;
        for(int i=1;i<=nums.size();i++){
            if(!mapp.count(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
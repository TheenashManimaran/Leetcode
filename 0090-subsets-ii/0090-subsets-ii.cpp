class Solution {
public:
    void subset(int ind, vector<int> ds, set<vector<int>> &ans, vector<int> arr){
        if(ind == arr.size()){
            ans.insert(ds);
            return;
        }
        ds.push_back(arr[ind]);
        subset(ind+1,ds,ans,arr);
        ds.pop_back();

        subset(ind + 1, ds, ans, arr);
    }

    void subset2(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);

        for(int i=ind;i<nums.size();i++){
            if(i > ind && nums[i-1] == nums[i]) continue;

            ds.push_back(nums[i]);
            subset2(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> ds;
        sort(nums.begin(), nums.end());

        //subset(0,ds,ans,nums);  

//  finding subsets and inserting it into set and finally converting set into vector (time consuming)

/*
        set<vector<int>> ans;
        vector<vector<int>> orig;
        for(auto it: ans){
            orig.push_back(it);
        }
        return orig;
*/

        vector<vector<int>> ans;

        subset2(0,nums,ds,ans);
        return ans;
    }
};
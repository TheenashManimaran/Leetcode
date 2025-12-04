class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n);

        arr.assign(nums.begin(), nums.end());

        sort(nums.begin(), nums.end(), greater<int>());

        map<int,int> mapp;
        for(int i=0;i<n;i++){
            int count = n-i-1;
    
            mapp[nums[i]] = count;     
        }
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i] = mapp[arr[i]];
        }

        return ans;
    }
};
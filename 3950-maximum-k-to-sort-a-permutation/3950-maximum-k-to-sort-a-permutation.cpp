class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int ans;
        int flag = 0;
        for(int i=0;i<n;i++){
            if(!flag && i != nums[i]){
                flag = 1;
                ans = nums[i]; 
            }
            else if(flag && i != nums[i]){
                ans &= nums[i];
            }

        }
        if (flag) return ans;
        else return 0;
    }
};
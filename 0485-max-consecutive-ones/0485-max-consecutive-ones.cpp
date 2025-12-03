class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cur = 1;

        int count = 0, maxi = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == cur){
                count++;
                maxi = max(maxi, count);
            }
            else{
                maxi = max(maxi, count);
                count = 0;  
            }
        }

        return maxi;

        
    }
};
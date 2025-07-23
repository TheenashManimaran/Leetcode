class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 1;
        int count = 0;
        int maxi = 0;
        int flag = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == cur && flag == 1){
                count++;

            } 
            else if(nums[i] == cur){
                count = 1;
                flag = 1;
            }
            else{
                maxi = max(maxi, count);
                count = 0;
                flag = 0;
            }
        }
        if(count != 0){
            maxi = max(maxi, count);
        }

        return maxi;
    }
};
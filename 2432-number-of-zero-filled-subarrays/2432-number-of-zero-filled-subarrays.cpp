class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int flag = 0;
        long long count = 0;

        for(int i=0;i<nums.size();i++){
            if(flag == 0 && nums[i] == 0){
                count++;
                flag = 1;
            }
            else if(flag && nums[i] == 0){
                count++;
            }
            else if(flag && nums[i] != 0){
                ans += (count * (count + 1)) / 2;
                count = 0;
                flag = 0;
            }
        }
        if(flag) ans += (count * (count + 1)) / 2;

        return ans;
    }
};
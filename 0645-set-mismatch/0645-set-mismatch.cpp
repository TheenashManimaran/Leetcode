class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        // to check
        vector<int> arr(n);  //  hash array

        vector<int> ans(2);
        int found = 0;
        for(int i=0;i<n;i++){
            if(arr[nums[i]-1] >= 1){
                ans[0] = nums[i];
            }
            else arr[nums[i]-1] += 1;
        }

        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                ans[1] = i+1;
                break;
            }
        }

        return ans;

        

           
    }
};
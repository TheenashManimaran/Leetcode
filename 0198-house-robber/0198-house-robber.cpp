class Solution {
public:
    // Space Optimization

    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = nums[0];
        int prev = nums[0];
        int cur;

        for(int i=1;i<n;i++){
            
            int take = nums[i];
            if(i - 2 >= 0) take += prev2;

            int notTake = 0 + prev;

            cur = max(take, notTake);

            prev2 = prev;
            prev = cur;
        }

        return prev;

    }
};
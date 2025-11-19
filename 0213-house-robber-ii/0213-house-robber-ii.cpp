class Solution {
public:
    
    int solve(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];


        int take = nums[ind] + solve(ind-2, nums, dp);

        int notTake = 0 + solve(ind-1, nums, dp);

        return dp[ind] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);

        int last_element = nums[nums.size() - 1];

        nums.assign(nums.begin() , nums.begin() + nums.size() -1);

        // nums[0...n-2]

        vector<int> dp(nums.size(), -1);
        int firstAns = solve(nums.size()-1, nums, dp);

        // nums[1...n-1]
        nums.erase(nums.begin());
        nums.push_back(last_element);

        fill(dp.begin(), dp.end(), -1);


        int secondAns = solve(nums.size()-1, nums, dp);

        return max(firstAns, secondAns);

        return 0;
    }
};
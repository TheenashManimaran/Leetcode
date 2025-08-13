class Solution {
    public int memoize(int ind, int[] arr, int[] dp){
        if(ind == 0) return arr[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = arr[ind] + memoize(ind-2,arr,dp);
        int notTake = 0 + memoize(ind-1,arr,dp);

        return dp[ind] = Math.max(take, notTake);
    }

    public int rob(int[] nums) {
        int n = nums.length;

        int[] dp = new int[n];
        for(int i=0;i<n;i++){
            dp[i] = -1;
        }
        return memoize(n-1, nums, dp);
    }
}
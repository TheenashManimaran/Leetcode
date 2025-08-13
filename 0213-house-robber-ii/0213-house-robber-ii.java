class Solution {
    public int toSolve(int n, int[] temp){
        int prev2 = 0, prev = temp[0];

        for(int i=1;i<n;i++){

            int take = temp[i];
            if(i - 2 >= 0) take += prev2;
            int nonTake = 0 + prev;

            int cur = Math.max(take, nonTake);
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];

        int[] temp = new int[n-1];
        for(int i=1;i<n;i++){
            temp[i-1] = nums[i];
        }

        int withoutFirst = toSolve(n-1, temp);

        for(int i=0;i<n-1;i++){
            temp[i] = nums[i];
        }

        int withoutLast= toSolve(n-1, temp);

        return Math.max(withoutFirst, withoutLast);


    }
}
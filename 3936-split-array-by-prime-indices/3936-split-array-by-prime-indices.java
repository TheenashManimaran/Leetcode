class Solution {

    boolean isPrime(int num){
        if(num == 0 || num == 1) return false;

        for(int i=2;i<=Math.sqrt(num);i++){
            if(num % i == 0) return false;
        }
        return true;
    }

    public long splitArray(int[] nums) {
        
        long sumA = 0,sumB = 0;

        for(int i=0;i<nums.length;i++){
            if(isPrime(i)){
                sumA += nums[i];
            }
            else{
                sumB += nums[i];
            }
        }

        return Math.abs(sumA - sumB);
    }
}
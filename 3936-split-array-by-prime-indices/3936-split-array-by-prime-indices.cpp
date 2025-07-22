class Solution {
public:

    bool isPrime(int num){
        if(num == 1 || num == 0) return false;

        for(int i=2;i<=sqrt(num);i++){
            if(num % i == 0) return false;
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {

        long long sumA = 0, sumB = 0;

        vector<long long> a,b;
        for(int i=0;i<nums.size();i++){
            if(isPrime(i)){
                a.push_back(nums[i]);
                sumA += nums[i];
            }
            else{
                b.push_back(nums[i]);
                sumB += nums[i];
            }
        }

        return abs(sumA - sumB);
    }
};
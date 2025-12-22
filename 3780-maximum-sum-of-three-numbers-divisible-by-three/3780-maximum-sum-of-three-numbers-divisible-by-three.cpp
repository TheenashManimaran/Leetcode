class Solution {
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
public:

    int maximumSum(vector<int>& nums) {
        vector<int> zero,one,two;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] % 3 == 0) zero.push_back(nums[i]);
            else if(nums[i] % 3 == 1) one.push_back(nums[i]);
            else two.push_back(nums[i]);
        }

        sort(rall(zero)); sort(rall(one)); sort(rall(two));
        
        int z = zero.size(), o = one.size(), t = two.size();

        int maxi = 0;
        if(z > 2) maxi = max(maxi, zero[0] + zero[1] + zero[2]);
        if(o > 2) maxi = max(maxi, one[0] + one[1] + one[2]);
        if(t > 2) maxi = max(maxi, two[0] + two[1] + two[2]);
        if(z > 0 && o > 0 && t > 0) maxi = max(maxi, one[0] + zero[0] + two[0]);

        return maxi;

    }
};
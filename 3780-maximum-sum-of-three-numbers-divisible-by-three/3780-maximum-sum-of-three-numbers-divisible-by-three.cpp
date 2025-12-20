class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> zero,one,two;

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] % 3 == 0) zero.push_back(nums[i]);
            else if(nums[i] % 3 == 1) one.push_back(nums[i]);
            else two.push_back(nums[i]);
        }
        sort(one.begin(), one.end());
        sort(zero.begin(), zero.end());
        sort(two.begin(), two.end());

        int z = zero.size(), o = one.size(), t = two.size();
        int a = 0, b = 0, c = 0;
        if(z > 0) a = zero[z-1];
        if(o > 0) b = one[o-1];
        if(t > 0) c = two[t-1];

        int maxi = 0;
        if(z > 0 && o > 0 && t > 0){
            maxi = max(maxi, a+b+c);
        }
        if(z > 2){
            maxi = max(maxi, zero[z-1] + zero[z-2] + zero[z-3]);
        }
        if(o > 2){
            maxi = max(maxi, one[o-1] + one[o-2] + one[o-3]);
        }
        if(t > 2){
            maxi = max(maxi, two[t-1] + two[t-2] + two[t-3]);
        }

        return maxi;


    }
};
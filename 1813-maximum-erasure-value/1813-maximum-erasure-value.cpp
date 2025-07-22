class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mapp;
        int n = nums.size();

        int i = 0, j = 0;

        int maxCount = 0, maxSum = 0;
        int sum = 0;
        int start,end;

        while(i<n && j<n){

            while(mapp.count(nums[j])){
                maxCount = max(maxCount, j - i - 1);
                sum = 0;
                for(int a = i; a<j;a++){
                    sum += nums[a];
                }
                maxSum = max(maxSum , sum);

                mapp[nums[i]]--;
                if(mapp[nums[i]] == 0) mapp.erase(nums[i]);
                i++;
            }

            mapp[nums[j]]++;
            j++;
        }
        sum = 0;
        for(auto &[x,y] : mapp){
            sum += x;
        }
        maxSum = max(sum, maxSum);
        maxCount = max(maxCount , (int)mapp.size());

        return maxSum;

    }
};
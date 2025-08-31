class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even, odd;

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i & 1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());


        int eveni  = 0, oddi = 0;
        for(int i=0;i<n;i++){
            if(i & 1) nums[i] = odd[oddi++];
            else nums[i] = even[eveni++];
        }

        return nums;
    }
};
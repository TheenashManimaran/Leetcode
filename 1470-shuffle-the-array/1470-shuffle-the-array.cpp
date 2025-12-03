class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr(2*n);

        int ind = 0;
        for(int i=0;i<n;i++){
            arr[ind++] = nums[i];
            arr[ind++] = nums[i+n];
        }

        return arr;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> hash(1e5);
        int n = nums.size();

        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(hash[nums[i]-1] >= 1) break;
            hash[nums[i]-1]++;
            cnt++;
        }
        cout<<n-cnt<<endl;

        return (n-cnt + 2)/3;
    }
};
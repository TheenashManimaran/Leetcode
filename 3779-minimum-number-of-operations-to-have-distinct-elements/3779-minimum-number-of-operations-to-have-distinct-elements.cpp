class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mapp;
        int n = nums.size();

        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(mapp[nums[i]]) break;
            mapp[nums[i]]++;
            cnt++;
        }
        cout<<n-cnt<<endl;

        return (n-cnt + 2)/3;
    }
};
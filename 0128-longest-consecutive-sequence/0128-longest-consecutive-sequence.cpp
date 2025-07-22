class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int,int> mapp;

        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
        }

        int maxi = 0;

        vector<int> arr;
        for(auto it: mapp){
            arr.push_back(it.first);
        }

        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }cout<<endl;

        int cur = arr[0];
        int count = 1;
        for(int i=1;i<arr.size();i++){
            if(arr[i] == cur + 1){
                cur = arr[i];
                cout<<"cur: "<<cur<<endl;
                count++;
            }
            else {
                maxi = max(maxi , count);
                cout<<maxi<<endl;
                cur = arr[i];
                count = 1;
            }
        }
        if(count != 0){
            maxi = max(maxi, count);
        }

        return maxi;
    }
};
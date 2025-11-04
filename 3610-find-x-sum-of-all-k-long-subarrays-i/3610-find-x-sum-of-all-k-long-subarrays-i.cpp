class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        vector<int> result;
        int n = nums.size();
        for(int i=0;i < n -k + 1 ; i++){

            map<int,int> mapp;
            for(int j=i; j<=i+k-1 && j<n ; j++){
                
                mapp[nums[j]]++;
            }
            vector<pair<int,int>> pairvec;
            for(auto it: mapp){
                pairvec.push_back({it.second, it.first});
            }

            sort(pairvec.begin(), pairvec.end(), greater<pair<int,int>>());

            // for(int i=0;i<pairvec.size();i++){
            //     cout<<pairvec[i].first<<"  "<<pairvec[i].second<<endl;
            // }cout<<endl;

            int sum = 0;
            for(int i=0;i<x && i < pairvec.size();i++){
                sum += pairvec[i].first * pairvec[i].second;
            }
            result.push_back(sum);
            

        }

        return result;


    }
};
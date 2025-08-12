class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int nn = queries.size();
        vector<long long> powers;
        
        long long num = 1;
        int i = 0;
        while(i <= 31){
            powers.push_back(num);
            //cout<<i<<" "<<num<<endl;
            i++;
            num *= 2;
        }
        

        // for(auto i: powers){
        //     cout<<i<<" ";
        // }cout<<endl;

        // vector<int> ans;
        // for(int i=0;i<nn;i++){
        //     int query = 1;
        //     for(int j=queries[i][0];j<=queries[i][1];j++){
        //         query *= powers[j];
        //     }
        //     query = query % 1000000007;
        //     ans.push_back(query);

        // }

        long long nCopy = n;
        int cnt = 0;
        while(nCopy != 0){
            nCopy/=2;
            cnt++;
        }
        //cout<<cnt<<endl;

        vector<long long> powArray;
        int sum = 0;
        for(i = cnt-1;i>=0;i--){
            sum += powers[i];
            if(sum < n){
                powArray.push_back(powers[i]);
            }
            else if(sum == n){
                powArray.push_back(powers[i]);
                break;
            }
            else{
                sum -= powers[i];
            }
        }
        int l = 0, r= powArray.size() - 1;
        while(l <= r){
            swap(powArray[l++], powArray[r--]);
        }

        for(auto i: powArray){
            cout<<i<<" ";
        }cout<<endl;

        vector<int> ans;
        for(int i=0;i<nn;i++){
            long long product = 1;
            for(int j=queries[i][0]; j<= queries[i][1]; j++){
                product = (product * powArray[j]) % 1000000007;
            }
            ans.push_back(product);
        }

        return ans;
        return {};
    }
};
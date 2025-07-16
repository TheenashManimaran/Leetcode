class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n);

        vector<int> arr;
        for(int i=0;i<s.size();i++){
            if(s[i] == c) arr.push_back(i);
        }

        for(int i=0;i<=arr[0];i++){
            ans[i] = abs(i - arr[0]);
        }
        if(arr.size() >= 2){
            int j = 1;
            int start = arr[0], end = arr[1];
            cout<<start<<" "<<end<<endl;
            for(int i=arr[0]+1;i<arr[arr.size()-1];i++){
                if(i <= end){
                    ans[i] = min(abs(i - start), abs(i - end));
                    if(i == 2){
                        cout<<abs(i - start)<<endl;
                        cout<<abs(i - end)<<endl;

                    }
                }
                else if(i > end){
                    start = end;
                    end = arr[j + 1];
                    i = i-1;
                    j = j+1;
                }
            }
        }
        

        for(int i = arr[arr.size() - 1];i<n;i++){
            ans[i] = abs(i - arr[arr.size() - 1]);
        }





        // compare index;
        // int j = 0;
        // int cind = arr[0];
        // int flag = 0;
        // int k;
        // for(int i=0;i<s.size();i++){
        //     if(i <= cind){
        //         flag = 0;
        //         ans[i] = abs(i - cind);
        //     }
        //     else if(i > k){
        //         j = j+1;
        //         cind = k;
        //         k = arr[j+1];
        //     }
        //     else if(i > cind && j+1 < arr.size()){
        //         k = arr[j+1];
        //         flag = 1;
        //     }
        //     if(flag == 1){
        //         ans[i] = min(abs(i-k), abs(i-cind));
        //     }
        // }

        return ans;
    }
};



/*
if(i == 6){
    cout<<"i:"<<i<<endl;
    cout<<"cind:"<<cind<<endl;
    cout<<"k:"<<k<<endl;

}

if(i == 7){
                        cout<<"start : "<<start<<endl;
                        cout<<"end : "<<end<<endl;
                        cout<<"i : "<<i<<endl;


                    }
*/
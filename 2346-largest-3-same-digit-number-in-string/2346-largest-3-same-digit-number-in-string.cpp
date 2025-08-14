class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        vector<string> numbers;

        string s = "";
        int cnt = 0;
        int flag = 0;
        for(int i=0;i<n-1;i++){
            if(num[i] == num[i+1] && flag == 0){
                s += num[i];
                s += num[i+1];
                cnt+=2;
                flag = 1;
            }
            else if(flag && num[i] == num[i+1] && cnt < 3){
                s += num[i+1];
                cnt++;
            }
            else if(flag && cnt == 3){
                numbers.push_back(s);
                cnt = 0;
                s = "";
                flag = 0;
                i--;
            }
            else if(flag && num[i] != num[i+1] && cnt < 3){
                flag = 0;
                s = "";
                cnt = 0;
            }
        }
        if(flag && cnt == 3){
            numbers.push_back(s);
        }

        for(auto i: numbers) cout<<i<<" ";
        cout<<endl;


        int maxi = INT_MIN;
        int ind = -1;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i].size() == 3){
                int num = stoi(numbers[i]);
                if(maxi < num){
                    maxi = num;
                    ind = i;
                }
            }
        }
        if(ind != -1) return numbers[ind];
        return "";
    }
};
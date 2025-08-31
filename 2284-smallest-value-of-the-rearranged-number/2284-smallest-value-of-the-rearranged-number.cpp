class Solution {
public:
    long long smallestNumber(long long num) {
        int flag = 1;

        if(num < 0) {flag = -1; num = -1 * num;}
        
        vector<int> nums;

        int countzero = 0;
        while(num!=0){
            if(num % 10 == 0) countzero++;
            else nums.push_back(num % 10);
            num /= 10;
        }
        long long number = 0;
        if(flag == 1){
            cout<<"flag :"<<flag <<endl;
            sort(nums.begin(), nums.end());
            if(countzero > 0){
                while(countzero--){
                    nums.insert(nums.begin() + 1, 0);
                }
            }
            long long places = 1;
            
            for(int i=nums.size() -1; i>=0 ;i--){
                number += nums[i] * places;
                places *= 10;
            }
        }
        else{
            sort(nums.begin(), nums.end(), greater<int>());
            if(countzero > 0){
                while(countzero--){
                    nums.push_back(0);
                }
            }
            long long places = 1;
            
            for(int i=nums.size() -1; i>=0 ;i--){
                number += nums[i] * places;
                places *= 10;
            }

            number = flag * number;

        }
        return number;
    }
};
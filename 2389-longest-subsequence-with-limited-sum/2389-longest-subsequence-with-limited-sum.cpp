class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        for(int &i: queries){
            int count = 0, sum = 0;
            
            for(int j=0;j<nums.size();j++){
                if(sum + nums[j] <= i){
                    sum += nums[j];
                    count++;
                }
            }

            i = count;
        }

        return queries;
    }
};
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        
        sort(skill.begin(), skill.end());

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += skill[i];
        } 
        int expAns = sum / (n/2);

        int i=0,j=n-1;
        long long product = 0;
        while(i<j){
            if(skill[i] + skill[j] != expAns){
                return -1;
            }
            product += skill[i] * skill[j];
            i++; j--;
            
        }
        return product;

        
    }
};
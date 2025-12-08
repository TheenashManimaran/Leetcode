class Solution {
public:
    int countTriples(int n) {
        
        int count = 0;
        
        // c = 1..n

        for(int c = 1;c<=n;c++){
            // to find a^2 + b^2 = c^2
            int target = c*c;
            int l = 1, r = c-1;

            while(l < r){
                int sum = (l*l) + (r*r);
                if(sum == target){
                    count+=2;
                    l++;
                    r--;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return count;

        return count;
    }
};
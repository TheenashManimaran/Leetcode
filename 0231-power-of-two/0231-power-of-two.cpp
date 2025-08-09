class Solution {
public:

    bool func(long long ans, int n){
        if(ans == n){
            return true; 
        }
        if(ans > n) return false;

        ans *= 2;
        return func(ans,n);
    }

    bool isPowerOfTwo(int n) {
        long long ans = 1;
        
        return func(ans,n);
    }
};
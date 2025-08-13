class Solution {
public:

    bool func(int n, long long pow){
        if(pow == n) return true;
        if(pow > n) return false;
        return func(n, pow * 3); 
    }

    bool isPowerOfThree(int n) {
        long long pow = 1;
        return func(n, pow);
    }
};
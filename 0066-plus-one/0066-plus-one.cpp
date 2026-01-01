class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();

        digits[n-1] += 1;

        int ind = n-1;
        int carry = 0;
        while(ind > -1){
            if(carry){
                digits[ind] += 1;
            }
            if(digits[ind] > 9){
                digits[ind] = 0;
                carry = 1;
            }
            else carry = 0;
            ind--;
            if(carry == 0) break;
        }

        if(digits[0] == 0){
            digits.insert(digits.begin(), 1);
        }

        return digits;
        
    }
};
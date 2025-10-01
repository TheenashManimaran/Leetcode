class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = numBottles;

        while(numBottles >= numExchange){
            int cur = numBottles / numExchange;
            drank += cur;
            cur += numBottles % numExchange;

            numBottles = cur;
        }

        return drank;
    }
};
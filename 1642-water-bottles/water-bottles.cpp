class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        int Exc = numBottles / numExchange;
        int rem = numBottles % numExchange;
        int x = Exc, y = rem;

        while(Exc + rem >= numExchange){
            count += Exc;
            Exc = (x + y)/numExchange;
            rem = (x + y)%numExchange;
            x = Exc;
            y = rem;
        }

        return count+Exc;
    }
};
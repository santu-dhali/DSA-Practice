class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // initially I want to store the first index to keep the track
        int iniVal = prices[0];
        int profit = 0;
        for(int i=1; i<n; i++){
            // if curr val of ind is less than inival
            if(prices[i] < iniVal){
                iniVal = prices[i];
            }else if(prices[i]-iniVal > profit){
                profit = prices[i] - iniVal;
            }
        }
        return profit;
    }
};
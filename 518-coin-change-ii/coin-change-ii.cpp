class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>&dp){
        if(ind<0 or amount<0){
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        int Take = 0;
        if(coins[ind] <= amount){
            Take = solve(ind, amount-coins[ind], coins, dp);
        }
        int notTake = solve(ind-1, amount, coins, dp);

        return dp[ind][amount] = (Take + notTake);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>>dp(2, vector<int>(2, 0));
        int maxi = 0;

        for(auto it: nums){
            for(int j=0; j<2; j++){
                int rem = it%2;
                maxi = max(maxi, dp[rem][j] = dp[j][rem]+1);
            }
        }
        return maxi;
    }
};
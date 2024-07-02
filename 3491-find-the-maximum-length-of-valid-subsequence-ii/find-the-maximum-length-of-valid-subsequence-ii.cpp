class Solution {
public:
    int maximumLength(vector<int>& nums, int k){
        vector<vector<int>>dp(k, vector<int>(k, 0));
        int maxi = 0;

        for(auto it: nums){
            for(int j=0; j<k; j++){
                int rem = it%k;
                maxi = max(maxi, dp[rem][j] = dp[j][rem]+1);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    bool solve(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(sum == 0) {
            return true;
        }
        if(ind == 0) {
            return (sum == nums[0]);
        }
        if (dp[ind][sum] != -1) {
            return dp[ind][sum];
        }
        
        bool notTake = solve(ind - 1, sum, nums, dp);
        bool take = false;
        if (sum - nums[ind] >= 0) {
            take = solve(ind - 1, sum - nums[ind], nums, dp);
        }
    
        return dp[ind][sum] = (take or notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(auto it: nums){
            sum += it;
        }
        if(sum%2 != 0){
            return false;
        }
        vector<vector<int>>dp(n, vector<int>(sum/2+1, -1));
        return solve(n-1, sum/2, nums, dp);
    }
};
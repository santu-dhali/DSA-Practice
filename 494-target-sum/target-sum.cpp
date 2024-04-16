class Solution {
public:
    int solve(int ind, vector<int>&nums, int target, vector<vector<int>>&dp){
        if(ind == 0){
            if(target==0 and nums[0]==0){
                return 2;
            }
            if(target==0 or nums[0]==target){
                return 1;
            }
            return 0;
        }
        
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        
        int notTake = solve(ind-1, nums, target, dp);
        int Take = 0;
        if(nums[ind]-target <= 0){
            Take = solve(ind-1, nums, target-nums[ind], dp);
        }
        
        return dp[ind][target] = (notTake + Take);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums){
            sum += it;
        }
        
        if((sum-target)%2!=0 or sum<target){
            return 0;
        }
        
        vector<vector<int>>dp(n, vector<int>((sum-target)/2+1, -1));
        return solve(n-1, nums, (sum-target)/2, dp);
    }
};
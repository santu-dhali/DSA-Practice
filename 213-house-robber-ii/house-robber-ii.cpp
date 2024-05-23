class Solution {
public:
    int solve(int ind, vector<int>&nums, vector<int>&dp){
        if(ind == 0){
            return nums[ind];
        }
        if(ind < 0){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }

        int take = nums[ind] + solve(ind-2, nums, dp);
        int nottake = 0 + solve(ind-1, nums, dp);
        return dp[ind] = max(take, nottake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n-1, -1);
        vector<int>first, last;

        for(int i=0; i<n-1; i++){
            first.push_back(nums[i]);
            last.push_back(nums[i+1]);
        }
        int s = first.size();
        int l = last.size();
        int left = solve(s-1, first, dp);
        vector<int>dp2(n-1, -1);
        int right = solve(l-1, last, dp2);

        return max(left, right);
    }
};
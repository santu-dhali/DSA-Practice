class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<int>&sol, vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(sol);
            return;
        }

        sol.push_back(nums[ind]);
        solve(ind+1, nums, sol, ans);
        sol.pop_back();
        solve(ind+1, nums, sol, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sol;
        solve(0, nums, sol, ans);
        return ans;
    }
};
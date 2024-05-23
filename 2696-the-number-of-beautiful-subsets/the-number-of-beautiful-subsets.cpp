class Solution {
public:
    void solve(int ind, vector<int>& nums, int n, int k, vector<vector<int>>&ans, vector<int>&sol){
        if(ind == n){
            for(int i=0; i<sol.size(); i++){
                for(int j=i+1; j<sol.size(); j++){
                    if(abs(sol[i]-sol[j]) == k){
                        return;
                    }
                }
            }
            ans.push_back(sol);
            return;
        }

        sol.push_back(nums[ind]);
        solve(ind+1, nums, n, k, ans, sol);
        sol.pop_back();
        solve(ind+1, nums, n, k, ans, sol);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>sol;

        solve(0, nums, n, k, ans, sol);
        int ansi = ans.size();
        return ansi-1;
    }
};
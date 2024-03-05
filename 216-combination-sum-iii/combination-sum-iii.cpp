class Solution {
public:
    void solve(int ind, int k, int target, vector<int>&temp, vector<vector<int>>&ans){
        if(k==0 and target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<=9; i++){
            if(target>0 and k>0){
                temp.push_back(i);
                solve(i+1, k-1, target-i, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp; 
        vector<vector<int>>ans;

        solve(1, k, n, temp, ans);
        return ans;
    }
};
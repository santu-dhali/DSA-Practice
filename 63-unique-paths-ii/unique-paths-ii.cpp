class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i==0 and j==0){
            return 1;
        }
        if(i<0 or j<0 or grid[i][j]==1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = solve(i-1, j, grid, dp);
        int left = solve(i, j-1, grid, dp);
        
        return dp[i][j] = (left+up);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>&v) {
        int n = v.size();
        int m = v[0].size();
        if (v[0][0]==1 or v[n-1][m-1]==1){
            return 0; 
        }
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, v, dp);
    }
};
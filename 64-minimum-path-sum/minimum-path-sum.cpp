class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i==0 and j==0){
            return grid[0][0];
        }
        if(i<0 or j<0){
            return 1e9;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = solve(i-1, j, grid, dp) + grid[i][j];
        int down = solve(i, j-1, grid, dp) + grid[i][j];

        return dp[i][j] = min(up, down);
        
    }
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if(i == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solve(i+1, j, n, triangle, dp) + triangle[i][j];
        int right_down = solve(i+1, j+1, n, triangle, dp) + triangle[i][j];

        return dp[i][j] = min(down, right_down);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, 0, n, triangle, dp);
    }
};
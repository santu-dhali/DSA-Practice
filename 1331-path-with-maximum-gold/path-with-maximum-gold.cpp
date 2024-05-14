class Solution {
public:
    int solve(int row, int col, int n, int m, vector<vector<int>>& grid, vector<pair<int, int>>&direc){
        if(row<0 or row>=n or col<0 or col>=m or grid[row][col]==0){
            return 0;
        }
        int pre = grid[row][col];
        grid[row][col] = 0;
        int maxi = pre;

        for(int i=0; i<4; i++){
            int nrow = row + direc[i].first;
            int ncol = col + direc[i].second;
            
            maxi = max(maxi, pre + solve(nrow, ncol, n, m, grid, direc));
        }

        grid[row][col] = pre;
        return maxi;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<pair<int, int>>direc = {{-1,0}, {1,0}, {0, 1}, {0,-1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    ans = max(ans, solve(i, j, n, m, grid, direc));
                }
            }
        }
        return ans;
    }
};
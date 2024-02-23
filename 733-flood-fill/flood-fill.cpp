class Solution {
public:
    vector<vector<int>>solve(vector<vector<int>>&image,  vector<vector<int>>&vis,  vector<vector<int>>&grid, int i, int j, int color){
        int colour1 = image[i][j];
        int n = image.size();
        int m = image[0].size();

        vis[i][j] = 1;
        queue<pair<int,int>>q;
        q.push({i, j});
        int direc[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            grid[row][col] = color;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + direc[i][0];
                int ncol = col + direc[i][1];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==colour1 and !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return grid;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<int>>grid = image;

        return solve(image, vis, grid, sr, sc, color);
    }
};
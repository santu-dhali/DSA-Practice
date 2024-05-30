class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>>q;
        int time = 0;;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int direc[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            time = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + direc[i][0];
                int ncol = col + direc[i][1];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]!=1 and grid[nrow][ncol] != 0){
                    q.push({{nrow, ncol}, time+1});
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
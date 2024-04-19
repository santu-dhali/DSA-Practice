class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int count = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' and vis[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    count++;
                }

                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();

                    for(int i=0; i<4; i++){
                        int nrow = row + dir[i][0];
                        int ncol = col + dir[i][1];

                        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1' and vis[nrow][ncol]==0){
                            q.push({nrow, ncol});
                            vis[nrow][ncol] = 1;
                        }
                    }
                }
            }
        }
        return count;
    }
};
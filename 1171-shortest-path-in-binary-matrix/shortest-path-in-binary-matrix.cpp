class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1){
            return -1;
        }
        vector<vector<int>>vec(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>>q;
        q.push({1, {0, 0}});
        vec[0][0] = 1;
        int direc[8][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int i=0; i<8; i++){
                int nrow = row + direc[i][0];
                int ncol = col + direc[i][1];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==0 and vec[nrow][ncol]>dis+1){
                    vec[nrow][ncol] = dis + 1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        if(vec[n-1][n-1] != INT_MAX){
            return vec[n-1][n-1];
        }
        return -1;
    }
};
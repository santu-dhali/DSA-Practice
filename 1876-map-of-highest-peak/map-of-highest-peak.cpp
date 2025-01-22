class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>ans(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    q.push({{i,j}, 0});
                    ans[i][j] = 0;
                }
            }
        }

        int direc[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int level = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + direc[i][0];
                int ncol = col + direc[i][1];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and ans[nrow][ncol] == -1){
                    q.push({{nrow, ncol}, level+1});
                    ans[nrow][ncol] = level+1;
                }
            }
        }

        return ans;
    }
};
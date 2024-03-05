class Solution {
public:
    bool solve(int nrow, int ncol, int n, int m, string &word, int size, vector<vector<char>>& board, vector<vector<int>>&vis){
        if(size >= word.size()){
            return 1;
        }
        if(nrow<0 or nrow>=n or ncol<0 or ncol>=m or board[nrow][ncol]!=word[size] or vis[nrow][ncol]==1){
            return 0;
        }
        
        if(board[nrow][ncol]==word[size] and vis[nrow][ncol]==0){
            vis[nrow][ncol] = 1;

            bool temp1 = solve(nrow+1, ncol, n, m, word, size+1, board, vis);
            bool temp2 = solve(nrow-1, ncol, n, m, word, size+1, board, vis);
            bool temp3 = solve(nrow, ncol+1, n, m, word, size+1, board, vis);
            bool temp4 = solve(nrow, ncol-1, n, m, word, size+1, board, vis);

            vis[nrow][ncol] = 0;
            return temp1 or temp2 or temp3 or temp4;
        }
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0] == board[i][j]){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            vector<vector<int>>vis(n,vector<int>(m,0));
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(solve(row, col, n, m, word, 0, board, vis)){
                return 1;
            }
        }
        return 0;
    }
};
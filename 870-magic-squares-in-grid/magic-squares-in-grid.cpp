class Solution {
public:
    bool solve(int rstart, int cstart, vector<vector<int>>& grid){
        vector<int>st;
        for(int i=rstart; i<rstart+3; i++){
            for(int j=cstart; j<cstart+3; j++){
                st.push_back(grid[i][j]);
            }
        }
        sort(st.begin(), st.end());
        //checking distinct number
        for(int i=0; i<9; i++){
            if(st[i] != i+1){
                return false;
            }
        }

        int sum = grid[rstart][cstart] + grid[rstart][cstart+1] + grid[rstart][cstart+2];

        //checking row
        for(int i=rstart; i<rstart+3; i++){
            if(grid[i][cstart] + grid[i][cstart+1] + grid[i][cstart+2] != sum){
                return false;
            }
        }

        //checking col
        for(int j=cstart; j<cstart+3; j++){
            if(grid[rstart][j] + grid[rstart+1][j] + grid[rstart+2][j] != sum){
                return false;
            }
        }

        //checking diagonal
        if(grid[rstart][cstart] + grid[rstart+1][cstart+1] + grid[rstart+2][cstart+2] != sum){
            return false;
        }
        if(grid[rstart][cstart+2] + grid[rstart+1][cstart+1] + grid[rstart+2][cstart] != sum){
            return false;
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        if(n<3 or m<3){
            return 0;
        }
        
        for(int i=0; i<=n-3; i++){
            for(int j=0; j<=m-3; j++){
                if(solve(i, j, grid)){
                    count++;
                }
            }
        }

        return count;
    }
};
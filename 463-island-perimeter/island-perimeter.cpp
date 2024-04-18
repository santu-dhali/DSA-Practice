class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int peri = 0;

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]==1){
                    peri += 4; 
                    if(col>0 and grid[row][col-1]==1){
                        peri -= 2;
                    }
                    if(row>0 and grid[row-1][col]==1){
                        peri -= 2;
                    }
                }
            }
        }
        return peri;
    }
};
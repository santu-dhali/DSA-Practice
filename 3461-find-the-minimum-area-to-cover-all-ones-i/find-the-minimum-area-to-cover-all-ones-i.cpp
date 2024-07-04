class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>height, width;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    width.push_back(i);
                    height.push_back(j);
                }
            }
        }

        sort(height.begin(), height.end());
        sort(width.begin(), width.end());

        int w = width.back()-width.front() + 1;
        int h = height.back()-height.front() + 1;

        return w*h;;
    }
};
class Solution {
public:
    
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long ans = LONG_MAX;
        long long first_row = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long second_row = 0;

        for(int i=0; i<n; i++){
            first_row -= grid[0][i];
            ans = min(ans, max(first_row, second_row));
            second_row += grid[1][i];
        }

        return ans;
    }
};
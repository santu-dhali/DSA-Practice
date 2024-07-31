class Solution {
public:
    int solve(int ind, vector<vector<int>>&books, int shelfWidth, vector<int>&dp){
        int n = books.size();
        if(ind == n){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }
        int ans=1e9, height=0, width=0;

        for(int i=ind; i<n; i++){
            width += books[i][0];
            if(width > shelfWidth){
                break;
            }
            height = max(height, books[i][1]);
            ans = min(ans, height + solve(i+1, books, shelfWidth, dp));
        }
        return dp[ind] = ans;

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size(), -1);
        return solve(0, books, shelfWidth, dp);
    }
};
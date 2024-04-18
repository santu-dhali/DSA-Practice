class Solution {
public:
    int LCS(int n, int m, string &text1, string &text2, vector<vector<int>>&dp){
        if(n==0 or m==0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }

        if(text1[n-1] == text2[m-1]){
            return dp[n][m] = 1 + LCS(n-1, m-1, text1, text2, dp);
        }else{
            return dp[n][m] = max(LCS(n, m-1, text1, text2, dp), LCS(n-1, m, text1, text2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return LCS(n, m, text1, text2, dp);
    }
};
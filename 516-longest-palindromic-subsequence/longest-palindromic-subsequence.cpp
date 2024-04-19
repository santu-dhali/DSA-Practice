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
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return LCS(n, n, s, t, dp);
    }
};
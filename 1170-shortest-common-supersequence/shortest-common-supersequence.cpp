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

    string shortestCommonSupersequence(string str1, string str2){
        int n = str1.size(), m = str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        LCS(n, m, str1, str2, dp);
        int i=n, j=m;
        string ans="";

        while(i>0 and j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }else{
                ans += str2[j-1];
                j--;
            }
        }

        while(i>0){
            ans += str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
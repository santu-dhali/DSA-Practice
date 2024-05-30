class Solution {
public:
    bool solve(int i, int j, string &p, string &s, vector<vector<int>>&dp){
        if(i<0 and j<0){
            return true;
        }
        if(i<0 and j>=0){
            return false;
        }
        if(i>=0 and j<0){
            for(int ind=0; ind<=i; ind++){
                if(p[ind] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(p[i] == s[j] or p[i] == '?'){
            return dp[i][j] = solve(i-1, j-1, p, s, dp);
        }else if(p[i] == '*'){
            return dp[i][j] = solve(i-1, j, p, s, dp) or solve(i, j-1, p, s, dp);
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, p, s, dp);
    }
};
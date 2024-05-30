class Solution {
public:
    long long giveAns(vector<vector<int>>& rides, int start, vector<long long>&dp) {
        if (start >= rides.size()){
            return 0; 
        }

        if (dp[start] != -1){
            return dp[start];
        }

        auto it = lower_bound(rides.begin(), rides.end(), rides[start][1], [](auto& vec, int value){ return vec[0] < value; });

        long long x = rides[start][2] + rides[start][1] - rides[start][0] + giveAns(rides, it - rides.begin(), dp);
        long long y = giveAns(rides, start + 1, dp);
        return dp[start] = max(x, y);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
       int m = rides.size();
       vector<long long>dp(m, -1);
        sort(rides.begin(), rides.end());
        return giveAns(rides, 0, dp);
    }
};
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours){
        unordered_map<int, int>mp;
        long long ans = 0;

        for(auto it: hours){
            ans += mp[(24 - it%24)%24];
            mp[it%24]++;
        }

        return ans;
    }
};
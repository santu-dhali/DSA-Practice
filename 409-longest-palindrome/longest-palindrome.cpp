class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>mp;
        int count = 0, ans = 0;

        for(auto it: s){
            mp[it]++;
        }

        for(auto it: mp){
            if(it.second%2 == 0){
                ans += it.second;
            }else{
                count = 1;
                ans += it.second - 1;
            }
        }
        if(count == 0){
            return ans;
        }else{
            return ans+1;
        }
    }
};
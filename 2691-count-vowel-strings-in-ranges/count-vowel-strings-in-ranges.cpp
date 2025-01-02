class Solution {
public:
    bool check(const string& str) {
        string vowels = "aeiou";
        int n = str.size();
        if(vowels.find(str[0]) != string::npos && vowels.find(str[n - 1]) != string::npos){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>ans;
        vector<int>prefixSum(n+1, 0);

        for(int i=0; i<n; i++){
            prefixSum[i+1] = prefixSum[i] + (check(words[i]) ? 1 : 0);
        }

        for(auto it: queries){
            int val = prefixSum[it[1]+1] - prefixSum[it[0]];
            ans.push_back(val);
        }

        return ans;
    }
};
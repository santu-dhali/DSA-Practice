class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void partition(int i, string s, vector<vector<string>>&ans, vector<string>&temp){
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<s.size(); j++){
            if(isPalindrome(s, i, j)){
                temp.push_back(s.substr(i, j-i+1));
                partition(j+1, s, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        partition(0, s, ans, temp);
        return ans;
    }
};
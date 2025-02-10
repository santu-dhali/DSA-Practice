class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        
        for(auto it: s){
            if(!isdigit(it)){
                ans += it;
            }else if(ans.size()>0){
                ans.pop_back();
            }
        }
        return ans;
    }
};
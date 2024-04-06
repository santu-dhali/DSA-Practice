class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int count = 0;
        string ans="";

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                count++;
            }else if(s[i] == ')'){
                if(count == 0){
                    s[i]='*';
                }else{
                    count--;
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(count == 0){
                break;
            }else if(count > 0 and s[i] == '('){
                count--;
                s[i]='*';
            }
        }

        for(int i=0; i<n; i++){
            if(s[i] != '*'){
                ans += s[i];
            }
        }

        return ans;
    }
};
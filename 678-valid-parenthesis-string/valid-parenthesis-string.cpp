class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int count = 0, mark=0;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                count++;
                mark++;
            }else if(s[i]==')'){
                count--;
                mark--;
            }else{
                count--;
                mark++;
            }

            if(mark<0){
                return false;
            }
            if(count<0){
                count=0;
            }
        }
        return count==0;
    }
};
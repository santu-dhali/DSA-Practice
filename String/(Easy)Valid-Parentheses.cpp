class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; s[i]!='\0'; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else {
                if(!st.empty()){
                    char top= st.top();
                    if(top=='(' && s[i]==')' or top=='{' && s[i]=='}' or top=='[' 
                       && s[i]==']'  ){
                        st.pop();
                    }else{
                      return false;
                  }
                }else{
                    return false;
                }
            }
        } if(st.empty()){
                return true;
            }else{
                return false;
            }
    }
};

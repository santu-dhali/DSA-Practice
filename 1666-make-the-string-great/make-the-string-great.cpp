class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char>st;
        string ans="";
        int i=0;
        st.push(s[i++]);
        
        while(i != n){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(abs(st.top()-s[i]) != 32){
                    st.push(s[i]);
                }else{
                    st.pop();
                }
            }
            i++;
        }
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
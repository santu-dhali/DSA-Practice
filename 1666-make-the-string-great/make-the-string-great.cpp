class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<int>st, st2;
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
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            ans += st2.top();
            st2.pop();
        }
        return ans;
    }
};
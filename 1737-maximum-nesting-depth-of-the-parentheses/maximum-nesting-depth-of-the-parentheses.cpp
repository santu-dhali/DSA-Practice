class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int count=0, ans = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(s[i]);
                count++;
            }else if(s[i] == ')'){
                st.pop();
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
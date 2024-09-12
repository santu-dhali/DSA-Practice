class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = allowed.size();
        int m = words.size();
        int ans = 0;

        for(int i=0; i<m; i++){
            unordered_set<char>st;
            int count = 0;
            
            for(auto it: words[i]){
                st.insert(it);
            }

            for(auto it: st){
                if(st.size() <= n and allowed.find(it) != string::npos){
                    count++;
                }else{
                    break;
                }
            }
            if(count == st.size()){
                ans++;
            }
        }
        return ans;
    }
};
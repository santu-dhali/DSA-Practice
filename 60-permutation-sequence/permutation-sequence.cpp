class Solution {
public:
    void solve(int n, int k, vector<string>&ans, string temp, vector<int>&vis){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        if(ans.size() == k){
            return;
        }

        for(int i=1; i<=n; i++){
            if(!vis[i-1]){
                vis[i-1] = 1;
                solve(n, k, ans, temp+to_string(i), vis);
                vis[i-1] = 0;
            }
        }
    }

    string getPermutation(int n, int k) {
        vector<string>ans;
        string temp="";
        vector<int>vis(n,0);

        solve(n, k, ans, temp, vis);
        return ans.back();
    }
};
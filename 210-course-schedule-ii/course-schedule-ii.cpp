class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& onPath, stack<int>& st){
	    vis[node] = 1;
        onPath[node] = 1;

	    for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (!dfs(neighbor, adj, vis, onPath, st)) return false;
            } else if (onPath[neighbor]) {
                return false;
            }
        }
        
        onPath[node] = 0;
        st.push(node);
        return true;
	}

    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int>adj[V];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        stack<int>st;
	    vector<int>vis(V,0);
	    vector<int> onPath(V, 0);
        vector<int> ans;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis, onPath, st)) {
                    return {};
                }
            }
        }

	    while(!st.empty()){
	        int node = st.top();
	        st.pop();
	        ans.push_back(node);
	    }
	    return ans;
    }
};
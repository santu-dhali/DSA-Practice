class Solution {
public: 
    bool validPath(int V, vector<vector<int>>&edges, int source, int destination){
        int n = edges.size();
        vector<int>adj[V];
        for(int i=0; i<n; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(source);
        vector<int>vis(V, 0);
        vis[source] = 1;

        while(!q.empty()){
            int nde = q.front();
            q.pop();
            if(nde == destination){
                return true;
            }
            for(auto it: adj[nde]){
                if(vis[it] != 1){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return false;
    }
};
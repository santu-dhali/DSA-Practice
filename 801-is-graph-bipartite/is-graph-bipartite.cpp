class Solution {
public:
    bool solve(int n, vector<int> adj[], queue<pair<int, int>>& q, vector<int>& vis) {
        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (vis[neighbor] == -1) {
                    vis[neighbor] = 1 - color;
                    q.push({neighbor, vis[neighbor]});
                } else if (vis[neighbor] == color) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];

        for (int i=0; i<n; i++) {
            for (int j=0; j<graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }

        queue<pair<int, int>> q;
        vector<int> vis(n, -1);

        for (int i=0; i<n; i++) {
            if (vis[i] == -1) {
                q.push({i, 0});
                vis[i] = 0;
                
                if (!solve(n, adj, q, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};

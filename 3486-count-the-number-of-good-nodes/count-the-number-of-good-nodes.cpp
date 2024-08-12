class Solution {
public:
    vector<vector<int>>adj;
    int ans = 0;
    
    int dfs(int node, int parent){
        int totalnode = 0;
        bool isGood = true;
        int subTree = -1;

        for(auto neighbour: adj[node]){
            if(neighbour == parent){
                continue;
            }
            int curr = dfs(neighbour, node);
            if(subTree == -1){
                subTree = curr;
            }else if(subTree != curr){
                isGood = false;
            }
            totalnode += curr;
        }
        if(isGood){
            ans++;
        }

        return totalnode+1;
    }
    int countGoodNodes(vector<vector<int>>& edges){
        int n = edges.size();
        adj.resize(n+1);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);
        return ans;
    }
};
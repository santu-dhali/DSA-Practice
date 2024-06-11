class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>>pq;
        vector<int>dis(n, 1e9);
        dis[src] = 0;
        pq.push({0, {src, 0}});

        while(!pq.empty() and pq.front().second.second <= k){
            int dist = pq.front().first;
            int node = pq.front().second.first;
            int val = pq.front().second.second;
            pq.pop();

            for(auto it: adj[node]){
                if(dist + it.second < dis[it.first]){
                    dis[it.first] = dist + it.second;
                    pq.push({dis[it.first], {it.first, val+1}});
                }
            }
        }
        if(dis[dst] == 1e9){
            return -1;
        }
        return dis[dst];

    }
};
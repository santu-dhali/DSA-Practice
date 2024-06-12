class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<pair<int, int>>adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int>dis(n+1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({src, 0});
        dis[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().first;
            int time = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                if(time + it.second < dis[it.first]){
                    dis[it.first] = time + it.second;
                    pq.push({it.first, dis[it.first]});
                }
            }
        }

        int maxTime = *max_element(dis.begin() + 1, dis.end());
        return maxTime == 1e9 ? -1 : maxTime;
    }
};
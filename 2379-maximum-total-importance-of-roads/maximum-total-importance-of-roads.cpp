class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads){
        vector<int>degree(n, 0);
        vector<int> cities(n);

        for(auto it: roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        for (int i = 0; i < n; i++){
            cities[i] = i;
        }
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });

        long long totalImportance = 0;
        for (int i = 0; i < n; i++) {
            totalImportance += (long long)(n - i) * degree[cities[i]];
        }
        
        return totalImportance;
    }
};
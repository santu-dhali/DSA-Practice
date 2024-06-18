class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> vec;
        int n = difficulty.size();
        int m = worker.size();
        
        for(int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }
        
        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());
        
        int i = 0, j = 0;
        int ans = 0;
        int maxi = 0;
        
        while (j < m) {
            while (i < n && vec[i].first <= worker[j]) {
                maxi = max(maxi, vec[i].second);
                i++;
            }
            ans += maxi;
            j++;
        }
        
        return ans;
    }
};

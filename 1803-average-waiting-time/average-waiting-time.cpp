class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();
        long long waittime = customers[0][1];
        long long cooking = customers[0][0] + customers[0][1];

        for(double i=1; i<n; i++){
            if(customers[i][0] < cooking){
                cooking += customers[i][1];
                waittime += cooking - customers[i][0];
            }else{
                cooking = customers[i][0] + customers[i][1];
                waittime += cooking - customers[i][0];
            }
        }

        double ans = waittime / n;
        return ans;
    }
};
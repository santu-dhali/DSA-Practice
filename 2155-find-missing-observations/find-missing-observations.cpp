class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        long val = (m + n)*mean;
        int sum = 0;
        for(auto it: rolls){
            sum += it;
        }
        long need = val - sum;
        vector<int>ans(n, 1);
        if(need<n or need>n*6){
            return {};
        }
        need -= n;
        for(int i=0; i<n; i++){
            ans[i] += min(long(5), need);
            need -= min(long(5), need);
            if(need <= 0){
                break;
            }           
        }
        return ans;
    }
};
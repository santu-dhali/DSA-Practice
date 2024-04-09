class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k){
        int n = tickets.size();
        int time = 0;
        int val = tickets[k];
        
        for(int i=0; i<n; i++){
            if(i<=k){
                time += min(tickets[i], val);
            }else{
                if(tickets[i]<val){
                    time += tickets[i];
                }else{
                    time += val-1;
                }
            }
        }

        return time;
    }
};
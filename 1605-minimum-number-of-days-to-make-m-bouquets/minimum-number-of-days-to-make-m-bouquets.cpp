class Solution {
public:
    bool possible(vector<int>&bloomDay, int day, int m, int k){
        int count=0, bloom=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }else{
                bloom += count/k;
                count=0;
            }
        }
        bloom += count/k;
        return (bloom >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = INT_MAX;

        if(bloomDay.size() < (long)m*k){
            return -1;
        }
        
        while(low <= high){
            int mid = low-(low-high)/2;
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
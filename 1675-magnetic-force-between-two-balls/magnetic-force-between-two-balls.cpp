class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin(), pos.end());
        int low = 1, high = pos.back() - pos[0];
        int ans = 1;

        while(low <= high){
            int mid = low + (high-low)/2;
            int balls = 1, lastPlaced = pos[0];

            for(int i=1; i<n; i++){
                if(pos[i]-lastPlaced >= mid){
                    balls++;
                    lastPlaced = pos[i];
                }
            }
            if(balls >= m){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};
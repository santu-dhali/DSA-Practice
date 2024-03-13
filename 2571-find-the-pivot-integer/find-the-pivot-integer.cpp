class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2, ans=0;

        for(int i=1; i<n+1; i++){
            ans += i;

            if(ans>sum){
                break;
            }else if(ans == sum){
                return i;
            }
            sum -= i;
        }
        return -1;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int count = 0;
        for(int i=0; i<k; i++){
            count += cardPoints[i];
        }
        int n = cardPoints.size();
        int m = n-k;
        int ans = count;

        for(int i=k-1; i>=0; i--){
            ans -= cardPoints[i];
            ans += cardPoints[m+i];
            count = max(ans, count);
        }
        return count;
    }
};

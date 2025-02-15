class Solution {
public:
    bool isPartitioned(int square, int n){
        if(n == square){
            return true;
        }
        if(square < n or n < 0){
            return false;
        }
        return isPartitioned(square/10, n-square%10) or isPartitioned(square/100, n-square%100) or isPartitioned(square/1000, n-square%1000);
    }
    int punishmentNumber(int n) {
        int punish = 0;
        
        for(int i=1; i<=n; i++){
            int square = i*i;
            if(isPartitioned(square, i)){
                punish += square;
            }
        }
        return punish;
    }
};
class Solution {
public:
    int passThePillow(int n, int time) {
        int cycleLength = n * 2 - 2;
        int pos = time % cycleLength;
        
        if (pos < n - 1) {
            return pos + 1;
        } else {
            return n - (pos - (n - 1));
        }
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int it: nums){
            ans ^= it;
        }
        int count = 0;
        while(k or ans){
            if((k%2) != ans%2){
                count++;
            }

            k /= 2;
            ans /= 2;
        }
        return count;
    }
};
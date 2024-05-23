class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxi = INT_MIN;
        int zeroCnt = 0;
        int n = nums.size();

        while(right < n){
            if(nums[right] == 0){
                zeroCnt++;
            }
            if(zeroCnt > k){
                if(nums[left] == 0){
                    zeroCnt--;
                }
                left++;
            } 
            if(zeroCnt <= k){
                maxi = max(maxi, right-left+1);
            }
            right++;
        }
        return maxi;
    }
};
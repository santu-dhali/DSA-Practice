class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n =nums.size();
        int i=0, j=0, count=0, ans=0;
        
        while(j<n){
            if(nums[j]%2 != 0){
                k--;
                count = 0;
            }
            while(k == 0){
                count++;
                if(nums[i]%2 != 0){
                    k++;
                }
                i++;
            }
            ans += count;
            j++;
        }
        return ans;
    }
};
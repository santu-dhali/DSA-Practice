class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int r = 1;
        int l = 0;
        int sum=nums[l], n = nums.size();
        while(r<n){
            sum+=nums[r];
            if(sum%k == 0){
                return true;
            }
            if(nums[r] == nums[r-1] && nums[r] == 0){
                return true;
            }
            int x = sum;
            l=0;
            while((r-l)>1 && x>=k){
                x-=nums[l++];
                if(x%k == 0) return true;
            }
            r++;
        }
        return false;
    }
};
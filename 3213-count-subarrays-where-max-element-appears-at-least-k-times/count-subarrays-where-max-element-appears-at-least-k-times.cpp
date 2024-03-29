class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int count = 0, ans=0;
        long long int n = nums.size();
        long long int left = 0, right = 0;
        long long int maxi = *max_element(nums.begin(), nums.end());

        while(right < n){
            if(nums[right] == maxi){
                count++;
            }
            while(count>=k){
                if(nums[left] == maxi){
                    count--;
                }
                left++;
                ans += n-right;
            }
            right++;
        }
        return ans;
    }
};
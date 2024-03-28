class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // using left and right as a pointer for keeping track of the winfow size of the subarray
        int n=nums.size(), left=0, right=0, ans=0;
        unordered_map<int,int>mp;  // keeping track of the frequency

        while(right<n){
            mp[nums[right]]++; // updating the frequency each time 

            //if frequency of right pointer exceeds K then decrease the frequency of left pointer and increase the left ponter untill it reaches equal element to right pointer
            
            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans, right-left+1); //updating the answer to get the length of the longest subarray
            right++; // increase right each time
        }
        return ans;
    }
};
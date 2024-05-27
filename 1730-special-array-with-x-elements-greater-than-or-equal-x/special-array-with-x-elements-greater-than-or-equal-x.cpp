class Solution {
public:
    int specialArray(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        if(nums[n-1] > n){
            return n;
        }
        if(nums[0] == 0){
            return -1;
        }

        int left = 0, right = n-1, mid = 0;

        while(left <= right){
            mid = left + (right-left)/2;

            if(nums[mid] > mid){
                left = mid+1;
            }else if(nums[mid] < mid){
                right = mid-1;
            }else{
                return -1;
            }
        }

        if(nums[mid] > mid){
            return mid+1;
        }else{
            return mid;
        }
    }
};
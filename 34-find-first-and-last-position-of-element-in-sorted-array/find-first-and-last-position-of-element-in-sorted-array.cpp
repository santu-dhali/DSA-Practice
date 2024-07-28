class Solution {
public:
    int firstInd(vector<int>&nums, int target){
        int n = nums.size();
        int low = 0, high = n-1;
        int f_ind = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                f_ind = mid;
                high = mid-1;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return f_ind;
    }
    int lastInd(vector<int>&nums, int target){
        int n = nums.size();
        int low = 0, high = n-1;
        int l_ind = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                l_ind = mid;
                low = mid+1;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return l_ind;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int findx = firstInd(nums, target);
        int lindx = lastInd(nums, target);
        return {findx, lindx};
    }
};
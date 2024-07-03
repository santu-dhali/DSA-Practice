class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        double count = DBL_MAX;

        for(int i=0; i<n/2; i++){
            count = min(count, (nums[i] + nums[n-i-1])/2.0);
        }

        return count;
    }
};
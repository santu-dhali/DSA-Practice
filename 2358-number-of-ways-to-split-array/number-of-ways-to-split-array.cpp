class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long  n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long int count = 0;
        long long sum = 0;;

        for(long long i=0; i<n-1; i++){
            sum += nums[i];
            if(sum >= total - sum){
                count++;
            }
        }

        return count;
    }
};
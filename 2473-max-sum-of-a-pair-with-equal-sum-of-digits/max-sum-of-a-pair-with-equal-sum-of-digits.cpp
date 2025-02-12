class Solution {
public:
    int digitSum(int number){
        int sum = 0;

        while(number != 0){
            int digit = number%10;
            sum += digit;
            number /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int maxi = -1;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>>mp;

        for(auto it: nums){
            int val = digitSum(it);
            mp[val].push_back(it);
        }

        for(auto it: mp){
            int size = it.second.size();
            if(size>1){
                maxi = max(maxi, it.second[size-1]+it.second[size-2]);
            }
        }

        return maxi;
    }
};
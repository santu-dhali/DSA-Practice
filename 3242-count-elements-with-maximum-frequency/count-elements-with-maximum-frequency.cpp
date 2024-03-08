class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi = 0, count = 0;

        for(auto it: nums){
            mp[it]++;
        }

        for(auto it: mp){
            maxi = max(maxi, it.second);
        }

        for(auto it: mp){
            if(it.second == maxi){
                count += it.second;
            }
        }

        return count;
    }
};
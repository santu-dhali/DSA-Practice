class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        int ans = 0;

        for(auto it: nums){
            mp[it]++;
            if(mp[it]>1){
                ans = it;
                break;
            }
        }
        return ans;
    }
};
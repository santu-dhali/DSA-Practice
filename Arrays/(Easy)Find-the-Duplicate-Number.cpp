class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n+1, 0);
        int ans = 0;
        for(auto it: nums){
            if(!vis[it]){
                vis[it] = 1;
            }else{
                ans = it;
            }
        }
        return ans;
    }
};

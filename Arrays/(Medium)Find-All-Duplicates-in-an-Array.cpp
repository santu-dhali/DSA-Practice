class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>ans, vis(n+1, 0);
        for(auto it: nums){
            if(!vis[it]){
                vis[it] = 1;
            }else{
                ans.push_back(it);
            }
        }
        if(ans.size() >=1){
            return ans;
        }else{
            return {};
        }
    }
};

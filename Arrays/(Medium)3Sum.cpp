class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int start = i+1;
            int end = n-1;

            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0){
                    st.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }else if(sum < 0){
                    start++;
                }else{
                    end--;
                }
            }
        }
        for(auto it: st){
            ans.push_back(it);
        }
        if(ans.size() >=1){
            return ans;
        }else{
            return {};
        }
    }
};

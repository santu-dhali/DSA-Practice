class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(), nums.end());

        for(int a=0; a<n; a++){
            for(int b=a+1; b<n; b++){
               int low = b+1, high = n-1;

               while(low < high){
                   long long sum =  (long long)nums[a] + nums[b] + nums[low] + nums[high];
                   if(sum == target){
                       st.insert({nums[a], nums[b], nums[low], nums[high]});
                       low++;
                       high--;
                   }else if(sum > target){
                       high--;
                   }else{
                       low++;
                   }
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

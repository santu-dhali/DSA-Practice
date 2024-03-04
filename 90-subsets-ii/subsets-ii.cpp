class Solution {
public:
void solve(int ind, vector<int>&arr, vector<vector<int>>&ans, vector<int>&temp){
       ans.push_back(temp);
            
        for(int i=ind; i<arr.size(); i++){
            if(i!=ind && arr[i]==arr[i-1]) continue;
            temp.push_back(arr[i]);
            solve(i+1, arr, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, nums, ans, temp);
        return ans;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        int k = st.size();
        nums.clear();
        for(auto it: st){
            nums.push_back(it);
        }
        return k;
    }
};

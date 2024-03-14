class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>st; // for maintaning the stack entry.
        unordered_map<int, int>mp;

        // we will traverse the nums2 array now and push the element in the stack
        // update the dictionary if top element of stack is lesser than element of num2 and remove from stack

        for(auto it: nums2){
            while(!st.empty() and st.top()<it){
                mp[st.top()] = it;
                st.pop();
            }
            st.push(it);
        }

        // Dictionary is updated based on the stack.
        // we will traverse num1 now and push greater element in ans.

        for(auto it: nums1){
            if(mp.find(it) != mp.end()){
                ans.push_back(mp[it]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
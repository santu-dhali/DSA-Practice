class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<pair<int, int>>st; // pair for storing the index value and the element in num.
        st.push({0, nums[0]});

        for(int i=1; i<2*n-1; i++){ // it's running 2*n-1 times due to the circular array.

            while(!st.empty() and st.top().second < nums[i%n]){ // checking if the top element is lesser than the current element

                ans[st.top().first] = nums[i%n]; // if it's found, ans[ind] is updated with the greater element
                st.pop();
            }
            st.push({i%n, nums[i%n]}); // we are pushing the elemet here in stack with is index and i%n is basically used for rotating the inedx after reaching n for circular array
        }
        return ans;
    }
};
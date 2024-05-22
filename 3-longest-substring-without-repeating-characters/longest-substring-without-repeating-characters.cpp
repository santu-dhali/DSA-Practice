class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int left=0, right = 0;
        int maxi = INT_MIN;
        vector<int>mp(256, -1);
        
        while(right < n){
            if(mp[s[right]] != -1){
                left = max(mp[s[right]]+1, left);
            }
            mp[s[right]] = right;
            maxi = max(maxi, right-left+1);
            right++;
        }

        // int left = 0;
        // unordered_set<int>st;

        // for(int j=0; j<n; j++){
        //     if(st.find(s[j]) != st.end()){
        //         while(left < j and st.find(s[j]) != st.end()){
        //             st.erase(s[left]);
        //             left++;
        //         }
        //     }
        //     st.insert(s[j]);
        //     maxi = max(maxi, j-left+1);
        // }

        return maxi;
    }
};
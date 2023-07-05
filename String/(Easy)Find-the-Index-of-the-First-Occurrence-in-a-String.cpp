class Solution {
public:
    int strStr(string haystack, string needle) {
        string ans = "";
        int n = haystack.size();
        int m = needle.size();

        for(int i=0; i<n; i++){
            ans += haystack[i];
            if(ans == needle){
                int res = m-i-1;
                return abs(res);
            }else if(ans.size() == m){
                ans.erase(ans.begin(), ans.begin()+1);
            }
        }
        return -1;
    }
};

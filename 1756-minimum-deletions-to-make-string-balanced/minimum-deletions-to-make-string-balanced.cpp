class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int count = 0, ans = 0;

        for(int i=0; i<n; i++){
            if(s[i] == 'b'){
                count++;
            }
            if(s[i] == 'a' and count){
                count--;
                ans++;
            }
        }
        return ans;

    }
};
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n-1;

        while(left<right and s[left]==s[right]){
            char ch=s[left];
            while(left <= right and s[left]==ch){
                left++;
            }
            while(left <= right and s[right]==ch){
                right--;
            }
        }
        return right-left+1;
    }
};
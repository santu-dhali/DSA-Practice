class Solution {
public:
    bool is_pal(string s, int i, int j){
        int n = s.size();

        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0; int j = n-1;
        
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                return (is_pal(s, i+1, j) or is_pal(s, i, j-1));
            }
        }
        return true;
    }
};

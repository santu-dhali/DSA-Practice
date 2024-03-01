class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int count = 0;
        
        for(int i=0; i<n; i++){
            count++;
        }
        if(count == 1){
            sort(s.begin(), s.end());
            return s;
        }else if(count>1){
            for(int i=n-1; i>=0; i--){
                sort(s.begin(), s.end(), greater<char>());
                if(s[i] == '1'){
                    swap(s[i], s[n-1]);
                    break;
                }
            }
        }
        return s;
    }
};
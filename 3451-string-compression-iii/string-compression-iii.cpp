class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        if(n == 0){
            return comp;
        }
        int i=0;

        while(i<n){
            int count = 0;
            char ch = word[i];

            while(i<n and count<9 and word[i]==ch){
                count++;
                i++;
            }

            comp += to_string(count)+ch;
        }
        return comp;
    }
};
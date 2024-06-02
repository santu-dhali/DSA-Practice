class Solution {
public:
    void helper(vector<char>&s,int i, int j)
    {
        if(i==(s.size()/2)) // only iterate through half of the array as we will be swapping the characters i.e not using extra space
            return;
        helper(s,i+1,j-1);
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
};
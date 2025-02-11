class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int size = part.size();
        char lastCh = part[size-1];

        for(auto currCh: s){
            ans += currCh;
            if(currCh == lastCh and ans.size()>=size){
                if(ans.substr(ans.size() - size) == part){
                    ans.erase(ans.size() - size);
                }
            }
        }

        return ans;
    }
};
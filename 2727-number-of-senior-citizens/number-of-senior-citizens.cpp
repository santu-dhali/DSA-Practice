class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int count = 0;

        for(auto detail: details){
            string s = detail.substr(11,2);
            if(stoi(s) > 60){
                count++;
            }
        }
        return count;
    }
};
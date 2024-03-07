class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (const auto& email : emails) {
            string processedEmail;

            for(auto c: email){
                if(c=='+' or c=='@'){
                    break;
                }else if(c=='.'){
                    continue;
                }else{
                    processedEmail += c;
                }
            }
            processedEmail += email.substr(email.find('@'));
            uniqueEmails.insert(processedEmail);
        }
        for(auto it: uniqueEmails){
            cout<<it<<" ";
        }
        return uniqueEmails.size();
    }
};
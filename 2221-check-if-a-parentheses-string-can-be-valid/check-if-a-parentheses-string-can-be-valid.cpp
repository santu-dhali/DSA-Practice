class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if(locked[i]=='0'){
                s[i]='*';
            }
        }
        
        stack<int>open,mark;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open.push(i);
            }else if(s[i]=='*'){
                mark.push(i);
            }else{
                if(!open.empty()){
                    open.pop();
                }else if(!mark.empty()){
                    mark.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open.empty() and !mark.empty()){
            if(open.top()<mark.top()){
                open.pop();
                mark.pop();
            }else{
                break;
            }
        }

        if(mark.size()%2 != 0){
            return false;
        }
        return (open.empty());

    }
};
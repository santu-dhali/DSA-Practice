class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular=0, square=0;

        for(auto it: students){
            if(it==0){
                circular++;
            }else{
                square++;
            }
        }

        for(auto it: sandwiches){
            if(it==1){
                if(square>0){
                    square--;
                }else{
                    break;
                }
            }else{
                if(circular>0){
                    circular--;
                }else{
                    break;
                }
            }
        }
        return circular + square;
    }
};
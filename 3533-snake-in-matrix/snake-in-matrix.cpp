class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands){
        int count = 0;
        for(auto it: commands){
            if(it == "DOWN"){
                count += n;
            }else if(it == "RIGHT"){
                count += 1;
            }else if(it == "UP"){
                count -= n;
            }else{
                count -= 1;
            }
        }

        return count;
    }
};
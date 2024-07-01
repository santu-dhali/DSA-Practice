class Solution {
public:
    int solve(int red, int blue){
        int height = 0, ind = 1;
        while(true){
            if(ind%2 == 1){
                if(red >= ind){
                    red -= ind;
                }else{
                    break;
                }
            }else{
                if(blue >= ind){
                    blue -= ind;
                }else{
                    break;
                }
            }
            height++;
            ind++;
        }
        return height;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red, blue), solve(blue, red));
    }
};
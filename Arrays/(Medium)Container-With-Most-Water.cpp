class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxWater = 0;

        while(right > left){
            maxWater = max(maxWater, min(height[left], height[right])*abs(left-right));
            
            if(height[right] <= height[left]){
                right--;
            }else{
                left++;
            }
        }
        return maxWater;
    }
};

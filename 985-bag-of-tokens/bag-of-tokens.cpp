class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int score = 0;
        int left = 0, right = n-1;
        int maxi = 0;

        sort(tokens.begin(), tokens.end());

        while(left<=right){
            if(power>=tokens[left]){
                power -= tokens[left];
                left++;
                score++;
            }else if(score > 0){
                score--;
                power += tokens[right];
                right--;
            }else{
                break;
            }
            maxi = max(score, maxi);
        }
        return maxi;
    }
};
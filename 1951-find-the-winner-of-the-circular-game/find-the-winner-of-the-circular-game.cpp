class Solution {
public:
    int findTheWinner(int n, int k){
        int wicket = 0;
        vector<int>circle;
        for(int i=1; i<=n; i++){
            circle.push_back(i);
        }
        while(circle.size() > 1){
            int nextEle = (wicket + k - 1) % circle.size();
            circle.erase(circle.begin() + nextEle);
            wicket = nextEle;
        }

        return circle.back();
    }
};
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck){
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int>reveal;
        reveal.push_back(deck[n-1]);

        for(int i=n-2; i>=0; i--){
            int curr = reveal.back();
            reveal.pop_back();
            reveal.push_front(curr);
            reveal.push_front(deck[i]);
        }

        vector<int>ans;
        for(auto it: reveal){
            ans.push_back(it);
        }
        return ans;
    }
};
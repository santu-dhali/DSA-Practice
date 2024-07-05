/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans, collect;
        ListNode* curr = head->next;
        ListNode* prev = head;
        int nde = 2;

        while (curr->next) {
            if ((curr->val > prev->val and curr->val > curr->next->val) or
                (curr->val < prev->val and curr->val < curr->next->val)) {
                collect.push_back(nde);
            }
            nde++;
            prev = curr;
            curr = curr->next;
        }

        if(collect.size() < 2){
            return {-1, -1};
        }

        int mini = INT_MAX;
        for(int i=0; i<collect.size()-1; i++){
            mini = min(mini, collect[i+1]-collect[i]);
        }
        int maxi = collect.back()-collect.front();
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};
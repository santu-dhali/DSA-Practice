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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> node;
        ListNode* curr = head;
        node.push_back(curr);
        int n=0;
        while (curr) {     
            curr=curr->next;
            node.push_back(curr);
            n++;
        }

        auto [q, r]=div(n, k);
       
        vector<int> iLen(k, q);
        fill(iLen.begin(), iLen.begin()+r, q+1);
        vector<ListNode*> ans(k, {});
        int beginIdx=0, endIdx;
        for (int i=0; i<k; i++) {
            beginIdx=(i==0) ? 0:beginIdx+iLen[i-1];
            endIdx=(iLen[i]==0)?beginIdx:beginIdx+iLen[i]-1;
            ans[i]=node[beginIdx];
            ListNode* last = node[endIdx];
            if (last) 
                last->next = NULL;
        }       
        return ans;
    }
};
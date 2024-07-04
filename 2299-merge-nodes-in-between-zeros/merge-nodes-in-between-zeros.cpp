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
    ListNode* mergeNodes(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        int sum = 0;
        ListNode* curr = new ListNode();
        ListNode* tail = curr;
        ListNode* pre = head->next;

        while(pre != NULL){
            if(pre->val != 0){
                sum += pre->val;
            }else{
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            }
            pre = pre->next;
        }
        return curr->next;
    }
};
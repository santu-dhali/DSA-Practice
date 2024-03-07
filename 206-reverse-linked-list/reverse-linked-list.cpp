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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr = head;
        if(head==NULL or head->next == NULL){
            return head;
        }

        while(curr!=NULL){
            curr = curr->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }
};
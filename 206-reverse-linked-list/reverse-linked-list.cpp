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
        //create a pointer and add head->next to it then move head and the pointer 
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(head==NULL or head->next==NULL){
            return head;
        }

        while(curr){
            curr = curr->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }
};
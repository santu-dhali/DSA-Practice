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

    void reorderList(ListNode* head) {
        if(head==NULL or head->next == NULL){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reverseList(slow->next);
        slow->next = NULL;

        ListNode* curr = head;
        ListNode* ptr = head;
        ListNode* ptr1 = rev;

        while(rev){
            curr = curr->next;
            ptr1 = rev->next;
            ptr->next = rev;
            rev->next = curr;

            ptr = curr;
            rev = ptr1;
        }
    }
};
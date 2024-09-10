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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* curr = head;

        while(curr->next != NULL){
            int val1 = curr->val;
            int val2 = curr->next->val;
            int gcd = __gcd(val1, val2);
            ListNode* nde = new ListNode(gcd);
            nde->next = curr->next;
            curr->next = nde;
            curr = curr->next->next;
        }
        return head;
    }
};
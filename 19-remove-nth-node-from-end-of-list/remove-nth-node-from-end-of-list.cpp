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
    int count(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        } return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        
        int cnt=count(head);
        if(n==cnt)return head->next;
        ListNode* curr=head;
        for(int i=1; i<cnt-n; i++){
            curr=curr->next;
        } 
          curr->next=curr->next->next;
        return head;
    } 
};
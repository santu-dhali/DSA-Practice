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
        ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        } return prev;
    }
     void insertAtTail(ListNode* &head, ListNode* &tail, int value){
        ListNode* temp= new ListNode(value);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }else{
            tail->next=temp;
            tail=temp;
        }
    }
     ListNode* add(ListNode* first, ListNode* second){
        ListNode* ansHead= NULL;
        ListNode* ansTail= NULL;
        int carry=0, sum=0;
        
        while(first or second or carry!=0){
            int val1=0,val2=0;
            if(first!=NULL){
                val1= first->val;
            }
            if(second!=NULL){
                val2= second->val;
            }
            sum = carry + val1 + val2;
            int digit= sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry= sum/10;
            
            if(first!=NULL){
                first= first->next;
            }
            if(second!=NULL){
                second= second->next;
            }
        }
            return ansHead;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* first= reverse(head);
        ListNode* second= first;
        
        ListNode* ans= add(first,second);
        ans= reverse(ans);
        return ans;
    }
};
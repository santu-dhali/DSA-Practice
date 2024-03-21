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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // create a curr pointer for list1 and take it to a-1
        // create another pointer and take it to b+1
        ListNode* curr = list1;
        ListNode* ptr1 = list1;
        for(int i=0; i<=b; i++){
            if(i<a-1){
                curr = curr->next;
            }
            ptr1 = ptr1->next;
        }

        // create pointer for list2 and take it to the list node
        ListNode* ptr2 = list2;
        while(ptr2->next != NULL){
            ptr2 = ptr2->next;
        }

        // now link curr with the list2 and ptr2 with the ptr1
        curr->next = list2;
        ptr2->next = ptr1;

        return list1;
    }
};
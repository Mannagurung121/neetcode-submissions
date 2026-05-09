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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode*check=head;
        int countPossible=0;
        while(countPossible<k){
          
            if(check==NULL){
                break;
            }
              countPossible++;
            check=check->next;

        }
        if(countPossible<k){
            return head;
        }

        ListNode*nextHead=NULL;
        ListNode*curr=head;
        ListNode*prev=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            nextHead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextHead;
            count++;
        }
        if(nextHead!=NULL){
            head->next=reverseKGroup(nextHead,k);
        }
        return prev;
    
    }
};

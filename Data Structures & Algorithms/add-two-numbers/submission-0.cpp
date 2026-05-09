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
    void reverseNode(ListNode*&node){
        ListNode*prev=NULL;
        ListNode*currNext=NULL;
        ListNode*curr=node;
        while(curr){
            currNext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=currNext;
        }
        node=prev;

    }
    void makeNode(ListNode*&newHead,ListNode*&newTail,int digit){
        if(newHead==NULL){
            newHead=new ListNode(digit);
            newTail=newHead;
        }
        else{
            newTail->next=new ListNode(digit);
            newTail=newTail->next;
        }
    }
    ListNode*solve(ListNode*l1,ListNode*l2){
      
        ListNode*curr1=l1;
        ListNode*curr2=l2;
        ListNode*newHead=NULL;
        ListNode*newTail=NULL;
        int sum=0;
        int carry=0;
        int nodeDigit=0;
        while(curr1&&curr2){
             sum=curr1->val+curr2->val+carry;
             nodeDigit=sum%10;
             carry=sum/10;
            makeNode(newHead,newTail,nodeDigit);
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            sum=curr1->val+carry;
            nodeDigit=sum%10;
            carry=sum/10;
            makeNode(newHead,newTail,nodeDigit);
            curr1=curr1->next;
        }
        while(curr2){
            sum=curr2->val+carry;
            nodeDigit=sum%10;
            carry=sum/10;
            makeNode(newHead,newTail,nodeDigit);
            curr2=curr2->next;
        }
        if(carry!=0){
        makeNode(newHead,newTail,carry);
            carry=carry/10;
        }
        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if(l1!=NULL &&l2==NULL){
        //     return l1;
        // }
        // if(l2!=NULL &&l1==NULL){
        //     return l2;
        // }
        // reverseNode(l1);
        // reverseNode(l2);
        ListNode*ans=solve(l1,l2);
        
        // reverseNode(ans);
        return ans;
    }
};

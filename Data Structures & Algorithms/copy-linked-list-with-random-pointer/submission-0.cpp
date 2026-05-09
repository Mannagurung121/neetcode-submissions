/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
          if(head==NULL ){
            return head;
        }
        Node*curr=head;
      
        while(curr){
            Node*currNext=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=currNext;
            curr=currNext;
           
        }
        curr=head;
        while(curr){
            if(curr->random==NULL){
                curr->next->random=NULL;
            }
            else{

                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node*newHead=head->next;
        Node*ans=newHead;
        curr=head;
        while(curr && newHead){
            if(curr->next){
            curr->next=curr->next->next;
            }
            if(newHead->next){
                newHead->next=newHead->next->next;
            }
            curr=curr->next;
            newHead=newHead->next;
        }
        return  ans;

    }
};

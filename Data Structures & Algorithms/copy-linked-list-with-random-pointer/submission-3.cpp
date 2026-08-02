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
        if(head == NULL)
    return NULL;
        Node* temp=head;

        while(temp){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;

        }

        temp=head;
        Node*  copyhead=temp->next;
        while(temp){
            if(temp->random)copyhead->random=temp->random->next;
            temp=copyhead->next;
            if(temp)copyhead=temp->next;
        }
        
        temp=head;
        copyhead=temp->next;
        Node* temp1=copyhead;

        while(temp){
             temp->next = temp->next->next;
            if(temp1->next)temp1->next=temp1->next->next;
           
            temp1=temp1->next;
            temp=temp->next;

        }
        return copyhead;

        
    }
};

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
    ListNode * reverse(ListNode *head){
        // ListNode *dummy=new ListNode(-1);
        // ListNode *temp=dummy;

        ListNode *prev=NULL;
        ListNode *curr=head;

        while(curr){
            ListNode *nextnode=curr->next;
            curr->next=prev;

            prev=curr;
            curr=nextnode;

        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *temp=head;
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *head2=slow->next;
        slow->next=NULL;

        ListNode *temp2=reverse(head2);

        while(temp2){
            ListNode *nn=temp2->next;
            
            temp2->next=temp->next;
            temp->next=temp2;
            temp=temp2->next;
            temp2=nn;
        }
        
        
    }
};

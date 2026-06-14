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
    ListNode* reverse_ll(ListNode *head){
        ListNode *prev=NULL;
        ListNode *nextn=NULL;
        ListNode *curr=head;
        while(curr){
            nextn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextn;
        }
        return prev;
    }
    void reorderList(ListNode* head) {

        ListNode * slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *newh=reverse_ll(slow->next);
        slow->next=NULL;
        ListNode * temp=head;
        ListNode *temp2;


        while(newh){
            temp2=newh->next;
            newh->next=temp->next;
            temp->next=newh;
            temp=newh->next;
            newh=temp2;

        }
       
        

        
    }
};

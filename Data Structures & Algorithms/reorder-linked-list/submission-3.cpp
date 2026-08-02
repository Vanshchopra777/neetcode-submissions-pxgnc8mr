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
    ListNode*  reverse_ll(ListNode* head){
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        ListNode* curr=head;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode*  fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* nexthead=slow->next;
        slow->next=NULL;


        ListNode* newh=reverse_ll(nexthead);

        ListNode* temp=head;
        while(temp && newh){
        ListNode* newrevnext=newh->next;
        newh->next=temp->next;
        temp->next=newh;
        temp=newh->next;
        newh=newrevnext;
        }




        
    }
};

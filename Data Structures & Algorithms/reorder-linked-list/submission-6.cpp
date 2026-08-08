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
    ListNode* rev(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next)
    return;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp=slow->next;
        slow->next=NULL;

        ListNode*revnode=rev(temp);


        ListNode* move=head;
        


        while(move && revnode){
            ListNode* revnext=revnode->next;
            revnode->next=move->next;
            move->next=revnode;
            move=move->next->next;
            revnode=revnext;



        }
     




        

        
    }
};

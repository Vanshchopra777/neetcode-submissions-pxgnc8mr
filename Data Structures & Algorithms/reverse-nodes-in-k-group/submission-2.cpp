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
    ListNode* getkth(ListNode* temp,int k){
        k--;
        while(temp && k){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse_ll(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr= head;
        ListNode* nxt=NULL;

        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;

            
        }
        return prev;
    }



    ListNode* reverseKGroup(ListNode* head, int k) {
       
        ListNode* temp=head;
        ListNode* dummy = new ListNode(0);
dummy->next = head;
        ListNode* prevlast=dummy;

        while(temp){
    
        ListNode* kth=getkth(temp,k);

        if(kth!=NULL){
        ListNode* nexthead=kth->next;
        kth->next=NULL;
        reverse_ll(temp);

        prevlast->next=kth;
        prevlast=temp;
        temp->next=nexthead;
        temp=nexthead;

        }
        
        else{
            prevlast->next=temp;
            break;
            
        }
        }

        return dummy->next;
        
    }
};

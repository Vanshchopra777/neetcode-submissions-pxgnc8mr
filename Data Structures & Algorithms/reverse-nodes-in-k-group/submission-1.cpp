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
    void reverse_ll(ListNode* head){
        ListNode* prev=NULL;
        ListNode* nextn=NULL;
        ListNode* curr=head;
        while(curr){
            nextn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextn;
        }

        
        
    }
    ListNode* get_k(ListNode* temp,int k){
        k--;
        while(k && temp ){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* nn;
        ListNode* prev=NULL;

        while(temp){
        ListNode* kth=get_k(temp,k);
        if(!kth){
            prev->next=temp;
            break;


        }
        nn=kth->next;
        kth->next=NULL;
        reverse_ll(temp);
        if(temp==head)head=kth;
        else{
            prev->next=kth;

        }
        prev=temp;
        temp=nn; 


        }
        return head;
        
    }
};

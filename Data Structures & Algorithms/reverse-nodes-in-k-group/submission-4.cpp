class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while (true) {

            // Find kth node
            ListNode* kth = prevGroup;

            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (kth == NULL)
                    return dummy.next;
            }

            // Save start of next group
            ListNode* nextGroup = kth->next;

            // Reverse current group
            ListNode* prev = nextGroup;
            ListNode* curr = prevGroup->next;

            while (curr != nextGroup) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous group to reversed group
            ListNode* oldHead = prevGroup->next;
            prevGroup->next = kth;

            // Move to next group
            prevGroup = oldHead;
        }
    }
};
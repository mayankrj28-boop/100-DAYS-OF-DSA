/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertionSortList(struct ListNode* head) {

    // Dummy node for sorted list
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {

        // Store next node
        struct ListNode* nextNode = curr->next;

        // Find correct position
        struct ListNode* prev = &dummy;

        while (prev->next != NULL &&
               prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert node
        curr->next = prev->next;
        prev->next = curr;

        // Move to next node
        curr = nextNode;
    }

    return dummy.next;
}

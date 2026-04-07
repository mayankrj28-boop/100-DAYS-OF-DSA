 structure of Node
struct Node {
    int data;
    Node* next;
};


class Solution {
public:
    bool removeLoop(Node* head) {
        
        if (head == NULL || head->next == NULL)
            return false;

        Node *slow = head, *fast = head;

        // Step 1: Detect loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No loop found
        if (slow != fast)
            return false;

        // Step 2: Find start of loop
        slow = head;

        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } 
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Remove loop
        fast->next = NULL;

        return true;
    }
};

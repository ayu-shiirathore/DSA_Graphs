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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode* temp = head;
        int length = 1;
        while (temp->next != NULL) {
            ++length;
            temp = temp->next;
        }
        
        // Connect the last node to the head to form a circle
        temp->next = head;
        
        k = k % length;
        int end = length - k;
        
        // Find the new tail node
        while (end--)
            temp = temp->next;
        
        // Set the new head and break the circle
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
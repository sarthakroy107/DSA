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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* l1 = new ListNode(0);
        ListNode* dummy1 = l1;
        ListNode* l2 = new ListNode(0);
        ListNode* dummy2 = l2;
        ListNode* curr = head;

        while(curr != NULL) {
            if(curr->val < x) {

                dummy1->next = curr;
                dummy1 = dummy1->next;
                curr = curr->next;
                dummy1->next = NULL;
            }
            else {

                dummy2->next = curr;
                dummy2 = dummy2->next;
                curr = curr->next;
                dummy2->next = NULL;
                
            }

        }

        dummy1->next = l2->next;
        
        return l1->next;
    }
};
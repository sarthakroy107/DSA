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
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = head->next;
        while(temp != NULL) {
            curr->next = prev;
            prev = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = prev;
        return curr;
    }

    ListNode* helper(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 || l2 || carry != 0) {
            int digit1 = l1? l1->val : 0;
            int digit2 = l2? l2->val : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum/10;
            ListNode* ptr = new ListNode(sum%10);
            temp->next = ptr;
            temp = temp->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        
        return dummy->next;
    }

public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverseList(l1);
        ListNode* r2 = reverseList(l2);
        ListNode* ans = helper(r1, r2);
        return reverseList(ans);
    }
};
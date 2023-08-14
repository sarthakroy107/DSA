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
        if(head == NULL || head->next == NULL) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        int length = 0;

        while(fast != NULL) {
            length++;
            fast = fast->next;
        }

        int x;
        if(length > k) x = k;
        else x = k%length;
        
        fast = head;
        cout<<length<<endl;
        cout<<x<<endl;

        while(x--) fast = fast->next;

        while(fast->next != NULL) {
            cout<<slow->val<<" "<<fast->val<<endl;
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        cout<<slow->val<<endl;
        return head;
    }
};
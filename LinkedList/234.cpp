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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(fast->next != NULL && fast->next->next != NULL ) {
            fast = fast->next->next;
            slow = slow->next;
            curr->next = prev;
            prev = curr;
            curr = slow;
        }

        cout<<head->val<<endl;

        if(fast->next == NULL) {
            cout<<"fast->next == NULL"<<endl;
            slow = slow->next;
            while(prev->val == slow->val) {
                cout<<"HERE"<<endl;
                if(slow->next == NULL && prev->next == NULL) return true;
                else if(slow->next == NULL || prev->next == NULL) return false;
                prev = prev->next;
                slow = slow->next;
            }
        }else {
            slow = slow->next;
            curr->next = prev;
            prev = curr;
            while(prev->val == slow->val) {
                cout<<"HERE"<<endl;
                if(slow->next == NULL && prev->next == NULL) return true;
                else if(slow->next == NULL || prev->next == NULL) return false;
                prev = prev->next;
                slow = slow->next;
            }
        }
        
        return false;

    }
};
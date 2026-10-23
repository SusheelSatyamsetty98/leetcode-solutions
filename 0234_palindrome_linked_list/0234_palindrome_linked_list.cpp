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
    ListNode * reverseLL(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *current = head;
        
        while(current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while((fast != nullptr) && (fast->next != nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast!= nullptr) //To skip middle if in case of odd length
            slow = slow->next;

        ListNode *rev = reverseLL(slow);
        slow->next = nullptr;
        while(rev != nullptr)
        {
            if(head->val != rev->val) return false;
            rev = rev->next;
            head = head->next;
        }
        
        return true;
    }
};

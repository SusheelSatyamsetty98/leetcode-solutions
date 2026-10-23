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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp2 = list2;
        ListNode *temp1 = list1;
        ListNode *merge = nullptr;
        ListNode *temp = nullptr;
        
        if(!list1 || !list2) return list1 ? list1 : list2;

        while(temp1 && temp2)
        {
            if(temp1->val < temp2->val)
            {
                if(merge == nullptr)
                    merge = temp = temp1;
                else {
                    temp->next = temp1;
                    temp = temp->next;
                }
                temp1 = temp1->next;
            }
            else
            {
                if(merge == nullptr)
                    merge = temp = temp2;
                else {
                    temp->next = temp2;
                    temp = temp->next;
                }
                temp2 = temp2->next;
            }
        }
        
        temp->next = temp1 ? temp1 : temp2;
        
        return merge;
    }
};
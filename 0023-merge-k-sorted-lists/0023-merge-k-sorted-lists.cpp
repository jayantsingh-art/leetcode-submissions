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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merged = NULL;

        if(lists.size() == 0) {
            return NULL;
        }
        if(lists.size() == 1) {
            return lists[0];
        }

        for(int i = 0; i < lists.size(); i++) {
            merged = merge2lists(merged, lists[i]);
        }

        return merged;
    }

    ListNode* merge2lists(ListNode* head1, ListNode* head2) {
        ListNode* curr1 = head1;
        ListNode* curr2 = head2;
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(curr1 && curr2) {
            if(curr1->val <= curr2->val) {
                temp->next = curr1;
                curr1 = curr1->next;
            } else {
                temp->next = curr2;
                curr2 = curr2->next;
            }

            temp = temp->next;
        }

        if(curr1) temp->next = curr1;
        else temp->next = curr2;

        return dummy.next; 
    }
};
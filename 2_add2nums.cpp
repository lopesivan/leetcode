/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            return addTwoNumbers(l1, l2, 0);
        }
    private:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int inc) {
            if(l1 == nullptr && l2 == nullptr && inc == 0) {
                return nullptr;
            }
            int val = inc + (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val);
            if(val >= 10) {
                inc = 1;
                val -= 10;
            } else {
                inc = 0;
            }
            ListNode* node = new ListNode(val);
            ListNode* res = addTwoNumbers(l1 == nullptr ? l1 : l1->next, l2 == nullptr ? l2 : l2->next, inc);
            node->next = res;
            return node;
        }
};

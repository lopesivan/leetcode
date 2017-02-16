#include <iostream>
#include <cassert>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head) {
    for(ListNode* iter = head; iter != nullptr; iter = iter->next) {
        std::cout << iter->val << " ";
    }
    std::cout << std::endl;
}

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* current = head;    
            while(current != nullptr) {
                ListNode* next = current->next;
                //std::cout << "*current = " << current->val
                //          << ", *next = " << (next == nullptr ? -1 : next->val) << std::endl;
                while(next != nullptr and next->val == current->val) {
                    current->next = next->next;
                    delete next;
                    next = current->next;
                }
                current = next;
            }
            return head;
        }
};


ListNode* build(std::vector<int> nums) {
    ListNode *head;
    ListNode *ptr;
    for(int i = 0; i < (int)nums.size(); ++i) {
        if(i == 0) {
            head = new ListNode(nums[0]);
            ptr = head;
        } else {
            ptr->next = new ListNode(nums[i]);
            ptr = ptr->next;
        }
    }
    return head;
}

ListNode* test(std::vector<int> nums) {
    ListNode *lst = build(nums);
    print_list(lst);
    Solution().deleteDuplicates(lst);
    print_list(lst);
    return lst;
}

bool check(ListNode* lst, std::vector<int> res) {
    ListNode *ptr = lst;
    int end = res.size();
    for(int i = 0; i < end; ++i, ptr = ptr->next) {
        //std::cout << "*ptr = " << (ptr == nullptr ? -1 : ptr->val) << ", res =" << res[i] << std::endl; 
        if(ptr != nullptr and ptr->val == res[i]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    assert(check(test({1, 2, 3, 4, 5, 6}), {1, 2, 3, 4, 5, 6}));
    assert(check(test({1, 1, 2, 2, 2, 3}), {1, 2, 3}));
    assert(check(test({1, 1, 1, 1}), {1}));
    assert(check(test({}), {}));
    assert(check(test({1}), {1}));
    return 0;
}

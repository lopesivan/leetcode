#include <iostream>
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
        bool isPalindrome(ListNode* head) {
            int len = 0;
            for(ListNode* iter = head; iter != nullptr; iter = iter->next) {
                ++len;
            }
            if(len <= 1) {
                return true;
            }
            //std::cout << "len = " << len << std::endl;
            ListNode* prev = head;
            ListNode* next = prev->next;
            head->next = nullptr;
            //reverse half
            for(int i = 0; i < len / 2 - 1; ++i) {
                ListNode* temp = next->next;
                next->next = prev;
                prev = next;
                next = temp;
            }
            ListNode* reversed = prev;
            //std::cout << "reversed: " << std::endl;
            //print_list(reversed);
            ListNode* last_half = len % 2 == 0 ? next : next-> next;
            //std::cout << "last half: " << std::endl;
            //print_list(last_half);
            while(reversed != nullptr and last_half != nullptr) { 
                if(reversed->val != last_half->val) {
                    return false;
                }
                reversed = reversed->next;
                last_half = last_half->next;
            }
            return true;
        }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 2, 1};
    //std::vector<int> nums = {1, 2, 2, 1};
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
    print_list(head);
    std::cout << sol.isPalindrome(head) << std::endl;
    return 0;
}

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // rs của ông
        ListNode* curr = head;    // head của ông
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // tmp của ông
            curr->next = prev;               // Đảo chiều mũi tên
            prev = curr;                     // Dịch chuyển prev tiến lên
            curr = nextNode;                 // Dịch chuyển curr tiến lên
        }
        
        return prev;
    }
};

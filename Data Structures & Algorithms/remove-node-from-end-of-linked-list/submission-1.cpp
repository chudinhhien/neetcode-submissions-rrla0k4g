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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Tạo nút giả đứng trước Head
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // 2. Cho Fast chạy trước n bước
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // 3. Cho cả hai cùng chạy đến khi Fast chạm đích (nút cuối)
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Lúc này Slow đang đứng TRƯỚC nút cần xóa
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        
        // Dùng delete trong C++ thay vì free của C ông nhé
        delete toDelete; 

        return dummy.next;
    }
};
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
        // 1. Tạo nút giả để làm điểm tựa
        ListNode dummy(0);
        ListNode* tmp = &dummy;

        // 2. Chạy khi cả hai danh sách đều còn phần tử
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            } else {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next; // Luôn tiến tmp lên nút vừa nối
        }

        // 3. Móc phần còn dư (nếu có)
        // Nếu list1 hết thì lấy list2, ngược lại lấy list1
        tmp->next = (list1 != nullptr) ? list1 : list2;

        // Trả về phần sau nút giả (đầu danh sách thật)
        return dummy.next;
    }
};
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
        using pi = pair<int, ListNode*>;

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for(ListNode* list : lists) {
            if(list != nullptr) {
                pq.push({list->val, list});
            }
        }

        ListNode dummy(0);

        ListNode* tail = &dummy;

        while(!pq.empty()) {
            pi tmp = pq.top();
            pq.pop();
            
            // THAY VÌ: ListNode* newNode = new ListNode(tmp.first);
            // HÃY DÙNG:
            ListNode* currentNode = tmp.second; // Lấy chính cái Node cũ ra
            
            tail->next = currentNode; // Nối cái Node cũ này vào danh sách kết quả
            tail = tail->next;
            
            // Đẩy thằng tiếp theo của danh sách đó vào Heap
            if(currentNode->next != nullptr) {
                pq.push({currentNode->next->val, currentNode->next});
        }
}


        return dummy.next;
    }
};

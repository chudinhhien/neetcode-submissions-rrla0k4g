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
            ListNode* newNode = new ListNode(tmp.first);
            tail->next = newNode;
            tail = tail->next;
            if(tmp.second->next != nullptr) pq.push({tmp.second->next->val, tmp.second->next});
        }


        return dummy.next;
    }
};

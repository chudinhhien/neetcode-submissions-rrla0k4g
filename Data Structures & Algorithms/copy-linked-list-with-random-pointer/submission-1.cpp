/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        
        Node* tmp = head;

        while(tmp != nullptr) {
            Node* copyNode = new Node(tmp->val);
            mp[tmp] = copyNode;

            tmp = tmp->next;
        }

        Node* rs = mp[head];

        while(head != nullptr) {
            mp[head]->next = mp[head->next];
            mp[head]->random = mp[head->random];
            head = head->next;
        }

        return rs;
    }
};

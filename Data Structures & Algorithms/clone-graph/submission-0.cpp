/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> mp;

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        Node* newNode = new Node();

        mp[node->val] = newNode;

        newNode->val = node->val;

        vector<Node*> newNeighbors;

        for(Node* it : node->neighbors) {           
            if(mp.find(it->val) != mp.end()) {
                newNode->neighbors.push_back(mp[it->val]);
            }else {
                newNode->neighbors.push_back(cloneGraph(it));
            }
        }

        return newNode;
    }
};

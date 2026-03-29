/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    vector<string> decodes;

    void decode(TreeNode* root) {
        if(root == nullptr) {
            decodes.push_back("null");
            return;
        }

        decodes.push_back(to_string(root->val));

        decode(root->left);
        decode(root->right);
    } 

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        decode(root);

        string result = "";

        for (int i = 0; i < decodes.size(); ++i) {
            result += decodes[i];
            // Nếu chưa phải phần tử cuối cùng thì thêm dấu phẩy
            if (i < decodes.size() - 1) {
                result += ","; 
            }
        }

        return result;
    }

    int idx = 0;

    TreeNode* encode(vector<string> nodes) {
        if(idx >= nodes.size() || nodes[idx] == "null") return nullptr;

        TreeNode* node = new TreeNode(stoi(nodes[idx]));

        idx++;

        node->left = encode(nodes);

        idx++;

        node->right = encode(nodes);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        vector<string> nodes;

        while(getline(ss, item, ',')) {
            if(item != "") {
                nodes.push_back(item);
            }
        }

        return encode(nodes);
    }
};

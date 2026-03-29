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

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        stack<pair<TreeNode*, int>> treeNodesSt;

        treeNodesSt.push({root, root->val});

        int cnt = 0;

        while(!treeNodesSt.empty()) {
            auto [node, currentMax] = treeNodesSt.top();
            treeNodesSt.pop();

            if(node->val >= currentMax) {
                ++cnt;
            }

            int newMax = max(node->val, currentMax);

            if(node->right!=nullptr) treeNodesSt.push({node->right, newMax});
            if(node->left!=nullptr) treeNodesSt.push({node->left, newMax});
        }

        return cnt;
    }
};

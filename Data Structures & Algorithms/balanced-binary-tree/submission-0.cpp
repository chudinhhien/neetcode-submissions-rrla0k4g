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
    int checkHeight(TreeNode* root) {
        if(root == nullptr) return 0;

        int heightL = checkHeight(root->left);
        if(heightL == -1) return -1;
        int heightR = checkHeight(root->right);
        if(heightR == -1) return -1;

        if(abs(heightL - heightR) > 1) return -1;

        return 1 + max(heightL, heightR);
    }

    bool isBalanced(TreeNode* root) {
        if(checkHeight(root) == -1) return false;
        return true;
    }
};
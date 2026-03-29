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
    int ans = -1;

    void searchKth(TreeNode* root, int k, int& i) {
        if (root == nullptr) return;

        searchKth(root->left, k, i);

        i++;

        if(i == k) {
            ans = root->val;
            return;
        }

        if(i < k) {
            searchKth(root->right, k, i);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        searchKth(root, k, count);
        return ans;
    }
};

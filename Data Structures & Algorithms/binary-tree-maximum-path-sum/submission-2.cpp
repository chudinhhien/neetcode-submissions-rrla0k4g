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
    int ans = INT_MIN;

    int helperCalcMaxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftMaxPath = max(0, helperCalcMaxPathSum(root->left));
        int rightMaxPath = max(0, helperCalcMaxPathSum(root->right));

        ans = max(ans, leftMaxPath + root->val + rightMaxPath);

        return root->val + max(leftMaxPath, rightMaxPath);
    }

    int maxPathSum(TreeNode* root) {
        helperCalcMaxPathSum(root);
        return ans;
    }
};

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

        int leftMaxPath = helperCalcMaxPathSum(root->left);
        int rightMaxPath = helperCalcMaxPathSum(root->right);

        if(leftMaxPath < 0) leftMaxPath = 0;
        if(rightMaxPath < 0) rightMaxPath = 0;

        ans = max(ans, leftMaxPath + root->val + rightMaxPath);

        return root->val + max(leftMaxPath, rightMaxPath);
    }

    int maxPathSum(TreeNode* root) {
        helperCalcMaxPathSum(root);
        return ans;
    }
};

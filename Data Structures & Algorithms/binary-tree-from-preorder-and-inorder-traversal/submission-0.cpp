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
    unordered_map<int, int> mp;

    TreeNode* helperBuildTree(vector<int>& preorder, int preStart, int preEnd, 
                            vector<int>& inorder, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int mid = mp[preorder[preStart]];

        int numLeft = mid - inStart;

        root->left = helperBuildTree(preorder, preStart + 1, preStart + numLeft,
                                    inorder, inStart, mid - 1);

        root->right = helperBuildTree(preorder, preStart + numLeft + 1, preEnd,
                                    inorder, mid + 1, inEnd);

        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i < inorder.size() ; i++) {
            mp[inorder[i]] = i;
        }

        return helperBuildTree(preorder, 0, preorder.size() - 1,
                        inorder, 0, inorder.size() - 1);
    }
};

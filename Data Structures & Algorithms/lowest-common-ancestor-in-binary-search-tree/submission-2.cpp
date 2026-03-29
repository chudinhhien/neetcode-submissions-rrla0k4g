class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // Nếu cả p và q đều nhỏ hơn root -> Sang trái
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // Nếu cả p và q đều lớn hơn root -> Sang phải
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Nếu một thằng nhỏ, một thằng lớn (hoặc một thằng chính là root)
            // -> Đây chính là điểm rẽ nhánh (LCA)
            else {
                return root;
            }
        }
        return nullptr;
    }
};
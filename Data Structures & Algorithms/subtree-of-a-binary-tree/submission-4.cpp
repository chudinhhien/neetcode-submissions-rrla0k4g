class Solution {
public:
    // Hàm isSameTree của ông giáo đã viết rất chuẩn, tận dụng lại luôn!
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Nếu cây gốc rỗng thì chắc chắn không chứa cây con nào
        if (root == nullptr) return false;

        // 1. Kiểm tra xem cây hiện tại có khớp luôn không
        if (isSameTree(root, subRoot)) return true;

        // 2. Nếu không khớp, đi tìm tiếp ở nhánh trái HOẶC nhánh phải
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
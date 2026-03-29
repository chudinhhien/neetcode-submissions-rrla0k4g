class Codec {
public:
    // ----------------------------------------------------
    // PHẦN 1: SERIALIZE (Mã hóa)
    // ----------------------------------------------------
    
    // Đưa thẳng cái ống nước 'out' vào đệ quy
    void encodeHelper(TreeNode* root, ostringstream& out) {
        if (root == nullptr) {
            out << "null,"; // Ghi thẳng chữ null và dấu phẩy
            return;
        }

        out << root->val << ","; // Ghi giá trị và dấu phẩy
        
        encodeHelper(root->left, out);
        encodeHelper(root->right, out);
    } 

    string serialize(TreeNode* root) {
        ostringstream out;
        encodeHelper(root, out);
        return out.str(); // Biến toàn bộ dữ liệu trong ống thành 1 chuỗi duy nhất
    }

    // ----------------------------------------------------
    // PHẦN 2: DESERIALIZE (Giải mã)
    // ----------------------------------------------------
    
    // Truyền thẳng cái luồng 'ss' vào, không cần mảng trung gian, không cần idx
    TreeNode* decodeHelper(stringstream& ss) {
        string item;
        // Hút 1 phần tử ra khỏi luồng, ngắt bởi dấu phẩy
        getline(ss, item, ','); 

        // Nếu hết luồng hoặc gặp null thì trả về đáy
        if (item == "" || item == "null") {
            return nullptr;
        }

        // Tạo nút hiện tại
        TreeNode* node = new TreeNode(stoi(item));

        // Đệ quy dựng nhánh trái, phải. Luồng 'ss' sẽ tự động trôi đi!
        node->left = decodeHelper(ss);
        node->right = decodeHelper(ss);

        return node;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data); // Tạo luồng dữ liệu từ chuỗi
        return decodeHelper(ss);
    }
};
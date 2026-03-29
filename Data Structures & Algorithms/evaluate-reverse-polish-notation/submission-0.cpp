class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; // Dùng long long để tránh tràn số và không cần parse lại string

        for (const string& token : tokens) {
            // Nếu là toán tử
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Lấy 2 số ra khỏi Stack
                // LƯU Ý: Số lấy ra TRƯỚC (top) là số thứ 2 (bên phải phép tính)
                long long num2 = st.top(); st.pop(); 
                long long num1 = st.top(); st.pop();
                
                // Tính toán và đẩy ngược kết quả vào Stack
                if (token == "+") st.push(num1 + num2);
                else if (token == "-") st.push(num1 - num2); // Quan trọng: num1 - num2
                else if (token == "*") st.push(num1 * num2);
                else st.push(num1 / num2); // Quan trọng: num1 / num2
            } 
            else {
                // Nếu là số thì chuyển sang long long rồi đẩy vào
                st.push(stoll(token));
            }
        }
        
        return st.top(); // Kết quả cuối cùng còn lại trong Stack
    }
};
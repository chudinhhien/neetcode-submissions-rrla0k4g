class Solution {
public:
    bool checkValid(char c1, char c2) {
        return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
    }

    bool isValid(string s) {
        stack<char> st;
        if(s.size()% 2!=0) return false;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }else {
                if(st.empty()) return false;
                if(checkValid(st.top(), c)) {
                    st.pop();
                }else {
                    return false;
                }
            }
        }

        if(!st.empty()) return false;
        return true;
    }
};

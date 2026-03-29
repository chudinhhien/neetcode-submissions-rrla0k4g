class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto chr:s){
            if(chr=='{' or chr=='(' or chr=='['){
                st.push(chr);
            }
            else{
                if(st.empty()) return false;
                if(
                    (chr==')' and st.top()=='(') or 
                    (chr==']' and st.top()=='[') or 
                    (chr=='}' and st.top()=='{')
                ){
                   st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};

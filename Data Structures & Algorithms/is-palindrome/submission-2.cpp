class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = "";
        for(char c : s) {
            if(isalnum(c)) {
                tmp += tolower(c);
            }
        }

        int i = 0 , j = tmp.length() - 1;
        while(i < j) {
            if(tmp[i] != tmp[j]){
                return false;
            }
            i++;j--;
        }

        return true;  
    }
};

class Solution {
public:
    vector<vector<string>> res;
    vector<string> currentList;

    bool isPalindrome(string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;right--;
        }

        return true;
    }

    void Try(string& s, int start) {
        if(start == s.length()) {
            res.push_back(currentList);
            return;
        }

        for(int i = start ; i < s.length(); i++) {
            if(isPalindrome(s, start, i)) {
                currentList.push_back(s.substr(start, i - start + 1));

                Try(s, i + 1);

                currentList.pop_back();
            }
        }
    }



    vector<vector<string>> partition(string s) {
        Try(s, 0);

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoder = "";
        for(string str : strs) {
            encoder += to_string(str.length()) + "#" + str;
        }
        return encoder;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i < s.length()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            string word = s.substr(j+1, length);
            result.push_back(word);

            i = j + length + 1;
        }

        return result;
    }
};

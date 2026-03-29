class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;

            for(int i = 0 ; i < 26 ; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root = new TrieNode();

    void insert(TrieNode* node, string word) {
        TrieNode* curr = node;

        for(char c : word) {
            int idx = c - 'a';

            if(curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isEndOfWord = true;
    }
    
    vector<string> rs;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1} ;
public:
    void dfs(TrieNode* node, int x, int y, vector<vector<char>>& board, string& currentWord) {
        char c = board[x][y];

        if(c == '#' || node->children[c - 'a'] == nullptr) {
            return;
        }

        TrieNode* nextNode = node->children[c - 'a'];
        currentWord += c;

        if(nextNode->isEndOfWord) {
            rs.push_back(currentWord);
            nextNode->isEndOfWord = false;
        }

        board[x][y] = '#';

        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                dfs(nextNode, nx, ny, board, currentWord);
            }
        }

        board[x][y] = c;
        currentWord.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        int n = board[0].size();
        int m = board.size();

        for(string word : words) {
            insert(root, word);
        }

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                string tmp = "";
                dfs(root, i, j , board, tmp);
            }
        }

        return rs;
    }
};
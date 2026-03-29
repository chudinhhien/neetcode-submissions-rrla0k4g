class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            for(int i = 0 ; i < 26 ; i++) {
                children[i] = nullptr;
                isEndOfWord = false;
            }
        }
    };

    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int idx = c - 'a';

            if(curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    bool helperSearch(TrieNode* curr, string& word, int idx) {
        if (curr == nullptr) return false;
        
        if(word.length() == idx) return curr->isEndOfWord;

        if(word[idx] == '.') {
            for(int i = 0 ; i < 26 ; i++) {
                if(curr->children[i]!= nullptr && helperSearch(curr->children[i], word, idx + 1)) {
                    return true;
                }
            }
            return false;
        }

        return helperSearch(curr->children[word[idx]-'a'], word, idx + 1);
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        return helperSearch(curr, word, 0);
    }
};

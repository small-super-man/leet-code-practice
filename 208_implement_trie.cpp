//
// Created by tangchao on 2022/5/30.
//

class Trie {
public:
    struct TrieNode {
      TrieNode *child[26];
      bool isLeaf;
      TrieNode() {
          for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
            isLeaf = false;
          }
      }
    };

    Trie() {
        root  = new TrieNode();
    }

    void insert(string word) {
       TrieNode *p = root;
       for (auto &e : word) {
            int idx = e - 'a';
            if (!p->child[idx]) {
                p->child[idx] = new TrieNode();
            }
            p = p->child[idx];
       }
       p->isLeaf = true;
    }

    bool search(string word) {
        TrieNode *p = root;
        for (auto &e : word) {
            int idx = e - 'a';
            if (!p->child[idx]) {
                return false;
            }
            p = p->child[idx];
        }

        return p->isLeaf;
    }

    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto &e : prefix) {
            int idx = e - 'a';
            if (!p->child[idx]) {
                return false;
            }
            p = p->child[idx];
        }

        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
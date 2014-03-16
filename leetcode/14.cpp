class Solution {
public:
    class Trie {
    public:
        bool insert(string s) {
            TrieNode *p = root;
            for (char c : s) {
                if (p->leaves.find(c) == p->leaves.end()) {
                    p->leaves[c] = new TrieNode();
                }
                p = p->leaves[c];
            }
            if (p->isStr) {
                return false;
            } else {
                p->isStr = true;
                return true;
            }
        }
        string findLongestCommonPrefix() {
            string prefix;
            TrieNode *p = root;
            while (p->leaves.size() == 1 && p->isStr == false) {
                prefix += p->leaves.begin()->first;
                p = p->leaves.begin()->second;
            }
            return prefix;
        }
    private:
        struct TrieNode {
            bool isStr = false;
            map<char, TrieNode *> leaves;
        };
        TrieNode *root = new TrieNode();
    };
    string longestCommonPrefix(vector<string> &strs) {
        Trie t;
        for (string &each : strs) {
            t.insert(each);
        }
        return t.findLongestCommonPrefix();
    }
    /*
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < strs[i].size() && j < prefix.size(); ++j) {
                if (prefix[j] != strs[i][j]) {
                    prefix = strs[i].substr(0, j);
                    continue;
                }
            }
            prefix = prefix.substr(0, min(prefix.size(), strs[i].size()));
        }
        return prefix;
    }
    */
};
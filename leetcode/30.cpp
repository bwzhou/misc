class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> start;
        int wordSize = L[0].size();
        unordered_map<string, int> count;
        for (auto &each : L) {
            ++count[each];
        }
        for (int i = 0; i <= (int) (S.size() - wordSize * L.size()); ++i) { // type-cast to 'int' to handle the case when the total size of L is greater than S because size_t is unsigned in C++ and int variables are 'promoted' to unsigned int
            unordered_map<string, int> see(count);
            for (int j = i; j <= S.size() - wordSize && !see.empty(); j += wordSize) {
                string word = S.substr(j, wordSize);
                if (see.find(word) == see.end()) {
                    break;
                }
                if (--see[word] == 0) {
                    see.erase(word);
                }
            }
            if (see.empty()) {
                start.push_back(i);
            }
        }
        return start;
    }
};
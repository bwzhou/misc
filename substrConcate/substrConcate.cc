#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> start;
    int wordSize = L[0].size();
    unordered_map<string, int> count;
    for (auto &each : L) {
        ++count[each];
    }
    for (int i = 0; i <= int(S.size() - wordSize * L.size()); ++i) {
        unordered_map<string, int> see(count);
        cout << i << "<=" << S.size() - wordSize * L.size() << endl;
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
int main() {
    string S = "a";
    vector<string> L{"a", "a"};
    for (int each : findSubstring(S, L)) {
        cout << each << endl;
    }
}

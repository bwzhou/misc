#include <iostream>
#include <vector>
#include <unordered_set>
#include <iterator>

using namespace std;

void wordBreakHelper(vector<vector<int> > &mark, string s, int start, unordered_set<string> &dict, string buffer, vector<string> &result) {
    cout << start << " " << s.size() << endl;
    copy(mark[start].begin(), mark[start].end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    if (start == s.size()) {
        result.push_back(buffer);
        return;
    }
    for (auto &next : mark[start]) {
        wordBreakHelper(mark, s, next, dict, buffer + " " + s.substr(start, next - start), result);
    }
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<vector<int> > mark(s.size(), vector<int>());
    vector<string> result;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                mark[i].push_back(j + 1);
            }
        }
    }
    cout << "finished mark" << endl;
    wordBreakHelper(mark, s, 0, dict, "", result);
    return result;
}

int main() {
  string s = "aaa";
  unordered_set<string> dict({"a","aa","aaa"});
  vector<string> result = wordBreak(s, dict);
  for (string &each : result)
    cout << each << endl;
}

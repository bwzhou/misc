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
    // the backward propagation order is important to prune fruitless searches
    // early on
    for (int stop = s.size(); stop >= 0; --stop) {
        if (stop < s.size() && mark[stop].empty()) {
          continue;
        }
        for (int start = stop - 1; start >= 0; --start) {
            if (dict.find(s.substr(start, stop - start)) != dict.end()) {
                mark[start].push_back(stop);
            }
        }
    }
    cout << "finished marking" << endl;
    wordBreakHelper(mark, s, 0, dict, "", result);
    return result;
}

int main() {
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
  unordered_set<string> dict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  vector<string> result = wordBreak(s, dict);
  for (string &each : result)
    cout << each << endl;
}

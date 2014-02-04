#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

int minCut(string s) {
    const int n = s.size();
    bool **pal = new bool*[n];
    for (int i = 0; i < n; ++i) {
        pal[i] = new bool[n];
        for (int j = 0; j < n; ++j) {
            pal[i][j] = false;
        }
    }
    for (int len = 1; len <= n; ++len) {
        for (int start = 0; start <= n - len; ++start) {
            int end = start + len - 1;
            if (start == end ||
                ((start == end - 1 || pal[start + 1][end - 1]) &&
                 s[start] == s[end])) {
                pal[start][end] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << "pal[" << i << "][" << j << "]=" << pal[i][j] << endl;
      }
    }
    
    int *cost = new int[n];
    cost[0] = 0;
    for (int i = 1; i < n; ++i) {
        cost[i] = i;
        if (pal[0][i]) {
          cost[i] = 0;
          continue;
        }
        for (int j = 0; j < i; ++j) {
            if (pal[j + 1][i]) {
                cost[i] = min(cost[i], cost[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
      cout << "cost[" << i << "]=" << cost[i] << endl;
    }

    return cost[n - 1];
}

void partitionHelper(string &s, int start, map<pair<int, int>, bool> &pal,
                     vector<string> &buf, vector<vector<string>> &result) {
    int n = s.size();
    if (start == n) {
        result.emplace_back(buf);
        return;
    }
    for (int end = start; end < n; ++end) {
        if (pal.find(make_pair(start, end)) == pal.end()) {
            if (start == end ||
                ((start + 1 == end ||
                  (pal.count(make_pair(start, end)) &&
                   pal[make_pair(start, end)])) &&
                 s[start] == s[end])) {
                pal[make_pair(start, end)] = true;
            } else {
                bool isPalindrome = true;
                for (int l = start, h = end; l < h; ++l, --h) {
                    if (s[l] != s[h]) {
                        isPalindrome = false;
                        break;
                    }
                }
                pal[make_pair(start, end)] = isPalindrome;

                cout << "pal[" << start << "][" << end << "]="
                     << pal[make_pair(start, end)] << endl;
            }
        }
        if (pal[make_pair(start, end)]) {
            buf.emplace_back(s.substr(start, end - start + 1));
            partitionHelper(s, end + 1, pal, buf, result);
            buf.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    map<pair<int, int>, bool> pal;
    vector<vector<string>> result;
    vector<string> buf;
    partitionHelper(s, 0, pal, buf, result);
    for (auto &each : pal) {
      cout << "pal: " << each.first.first << " " << each.first.second << " " << each.second << endl;
    }
    return result;
}

int main(int argc, char **argv) {
  cout << minCut(argv[1]) << endl;
  for (auto &each : partition(argv[1])) {
    copy(each.begin(), each.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
  }
}

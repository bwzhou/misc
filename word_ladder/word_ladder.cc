#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

void genPaths(string end, string start,
              unordered_map<string,
              unordered_set<string>> &last,
              vector<vector<string>> &result,
              vector<string> &path) {
    path.push_back(end);
    if (end == start) {
        result.push_back(vector<string>(path.rbegin(), path.rend()));
    } else {
      for (const auto &each : last[end]) {
          genPaths(each, start, last, result, path);
      }
    }
    path.pop_back();
}

vector<vector<string>> findLadders(const string &start, const string &end,
                                   unordered_set<string> &dict) {
    vector<vector<string>> result;
    vector<unordered_set<string>> level(2);
    int currLevel = 0, nextLevel;
    unordered_set<string> visited;
    unordered_map<string, unordered_set<string>> last;
    bool found = false;
    
    level[currLevel].insert(start);
    visited.insert(start);
    while (true) {
        for (const auto &curr : level[currLevel]) {
            nextLevel = currLevel ^ 1;
            string tmp(curr);
            for (int i = 0; i < tmp.size(); ++i) {
                char copy = tmp[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (j != copy) {
                        tmp[i] = j;
                        if (dict.count(tmp) > 0 && visited.count(tmp) == 0) {
                            level[nextLevel].insert(tmp);
                            last[tmp].insert(curr);
                            if (tmp == end) {
                                found = true;
                            }
                        }
                    }
                }
                tmp[i] = copy;
            }
        }
        if (found) {
            vector<string> path;
            for (const auto &each : last) {
              cout << each.first << ":";
              for (const auto &each2 : each.second) {
                cout << each2 << " ";
              }
              cout << endl;
            }
            genPaths(end, start, last, result, path);
            break;
        }
        if (level[nextLevel].empty()) {
          return result;
        }
        for (const auto &each : level[nextLevel]) {
            visited.insert(each);
        }
        level[currLevel].clear();
        currLevel = nextLevel;
    }
    return result;
}

void bfs(const string &start, const string &end,
         unordered_set<string> &dict,
         vector<vector<string>> &ret) {
    size_t len = start.size();
    if (len != end.size() || len == 0 || start == end) return; // invalid

    unordered_set<string> used;
    unordered_set<string> levelUsed;
    unordered_map<string, unordered_set<string>> father; // use it to get path

    queue<string> q;
    q.push(start);
    int levelSize = 1;
    bool found = false;

    while (!q.empty()) {
        string cur = q.front();
        string t(cur);
        q.pop();
        levelSize--;

        for (size_t i = 0; i < len; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (t[i] == c) continue; // itself

                t[i] = c;
                if (t == end) { // find it
                    found = true;
                    father[t].insert(cur);
                    break;
                }

                // t is not used and is in the dict
                if (used.count(t) == 0 && dict.count(t) != 0) {
                    //q.push(t);
                    levelUsed.insert(t);
                    father[t].insert(cur);
                }
            }
            t[i] = cur[i]; // reset t to cur
        }

        if (levelSize == 0) { // finish one level
            if (found) break;
            for (auto e : levelUsed) {used.insert(e); q.push(e);}
            levelSize = q.size();
            levelUsed.clear();
        }
    }

    if (found) {
        for (const auto &each : father) {
          cout << each.first << ":";
          for (const auto &each2 : each.second) {
            cout << each2 << " ";
          }
          cout << endl;
        }
        vector<string> path;
        genPaths(end, start, father, ret, path);
    }

}

vector<vector<string>> findLadders2(const string &start, const string &end,
                                    unordered_set<string> &dict) {
    vector<vector<string>> ret;
    bfs(start, end, dict, ret);
    return ret;
}

int main() {
  unordered_set<string> dict = {"hot","cog","dog","tot","hog","hop","pot","dot"};
  findLadders2("hot", "dog", dict);
  findLadders("hot", "dog", dict);
  return 0;
}

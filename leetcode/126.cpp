class Solution {
public:
    void genPaths(string end, string start, unordered_map<string, unordered_set<string>> &last,
                  vector<vector<string>> &result, vector<string> &path) {
        path.emplace_back(end);
        if (end == start) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));
        }
        for (const auto &each : last[end]) {
            genPaths(each, start, last, result, path);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        vector<vector<string>> result;
        vector<unordered_set<string>> level(2); // alternate two vectors to traverse by level
        int currLevel = 0, nextLevel;
        unordered_map<string, unordered_set<string>> last;
        unordered_set<string> visited;

        level[currLevel].insert(start);
        visited.insert(start);
        while (true) {
            for (const auto &curr : level[currLevel]) {
                nextLevel = (currLevel + 1) % 2;
                string tmp(curr);
                for (int i = 0; i < tmp.size(); ++i) {
                    char copy = tmp[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        if (j != copy) {
                            tmp[i] = j;
                            if (dict.count(tmp) > 0 && visited.count(tmp) == 0) {
                                level[nextLevel].insert(tmp);
                                last[tmp].insert(curr);
                            }
                        }
                    }
                    tmp[i] = copy;
                }
            }
            if (level[nextLevel].count(end)) {
                vector<string> path;
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
};
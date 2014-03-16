class Solution {
public:
    string minWindow(string S, string T) {
        int totalFound = 0;
        unordered_map<char, int> hasFound;
        unordered_map<char, int> needToFind;
        int minSize = S.size();
        int minStart = 0;
        int minEnd = S.size() - 1;
        for (auto &each : T) {
            ++needToFind[each];
        }
        int start, end;
        for (start = end = 0; end < S.size(); ++end) {
            if (needToFind.find(S[end]) != needToFind.end()) {
                if (hasFound[S[end]] < needToFind[S[end]]) {
                    ++totalFound;
                }
                ++hasFound[S[end]];
                if (totalFound == T.size()) {
                    while (start < end) {
                        if (needToFind.find(S[start]) != needToFind.end()) {
                            if (hasFound[S[start]] == needToFind[S[start]]) {
                                break;
                            }
                            --hasFound[S[start]];
                        }
                        ++start;
                    }
                    int windowSize = end - start + 1;
                    if (windowSize < minSize) {
                        minSize = windowSize;
                        minStart = start;
                        minEnd = end;
                    }
                }
            }
        }
        if (totalFound == T.size()) {
            return S.substr(minStart, minSize);
        } else {
            return "";
        }
    }
};
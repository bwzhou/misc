#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> fullJustify(vector<string> &words, int L) {
    if (L == 0) {
        return vector<string>{""};
    }
    vector<string> result;
    int length = 0;
    int start = 0;
    int curr = 0;
    for (auto &each : words) {
        if (length + each.size() + curr - start > L) {
            int count = curr - 1 - start;
            int spaces = L - length;
            int spaceNum = count ? spaces / count : 0;
            int spaceExtra = count ? spaces % count : 0;
            string line;
            for (int i = start; i < curr - 1; ++i) {
                line += words[i] + string(spaceNum, ' ');
                if (i < start + spaceExtra) {
                    line += " ";
                }
            }
            line += words[curr - 1];
            line += string(L - line.size(), ' ');
            result.emplace_back(line);
            length = 0;
            start = curr;
        }
        length += each.size();
        ++curr;
    }
    string line;
    for (int i = start; i < words.size() - 1; ++i) {
        line += words[i] + " ";
    }
    line += words.back();
    line += string(L - line.size(), ' ');
    result.emplace_back(line);
    return result;
}

int main() {
  vector<string> words = {"Listen","to","many,","speak","to","a","few."};
  for (auto &each : fullJustify(words, 6))
    cout << "'" << each << "'" << endl;
}


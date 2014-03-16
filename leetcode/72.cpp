class Solution {
public:
    int min3(int v1, int v2, int v3) {
        return min(min(v1, v2), v3);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> D(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); ++i) {
            D[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); ++j) {
            D[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    D[i][j] = D[i - 1][j - 1];
                } else {
                    D[i][j] = min3(D[i - 1][j - 1], D[i - 1][j], D[i][j - 1]) + 1;
                }
            }
        }
        return D[word1.size()][word2.size()];
    }
};
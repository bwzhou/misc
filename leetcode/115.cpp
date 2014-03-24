class Solution {
public:
/*
    int numDistinct(string S, string T) {
        if (S.empty()) {
            return 0;
        }
        vector<vector<int>> counter(T.size(), vector<int>(S.size(), 0));
        for (int i = 0; i < S.size(); ++i) {
            counter[0][i] = (T[0] == S[i] ? 1 : 0);
        }
        for (int i = 1; i < T.size(); ++i) {
            for (int j = i; j < S.size(); ++j) {
                if (T[i] == S[j]) {
                    for (int k = i - 1; k < j; ++k) {
                        counter[i][j] += counter[i - 1][k];
                    }
                }
            }
        }
        int result = 0;
        for (auto &each : counter[T.size() - 1]) {
            result += each;
        }
        return result;
    }
*/
/*
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        int tmp1, tmp2;
        // count[i, j] = count[i - 1, j] + S[i] == T[j] ? count[i - 1, j - 1] : 0
        // count[i, 0] = count[i - 1, 0] + S[i] == T[j] ? 1 : 0
        vector<int> count(m, 0); // by S
        for (int j = 0; j < n; ++j) {
            tmp1 = (j == 0 ? 1 : 0);
            for (int i = 0; i < m; ++i) {
                tmp2 = tmp1;
                tmp1 = (j == 0 ? 1 : count[i]);
                count[i] = (i == 0 ? 0 : count[i - 1]);
                if (S[i] == T[j]) {
                    count[i] += tmp2;
                }
            }
        }
        return m == 0 ? 0 : count[m - 1];
    }
*/
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        int tmp1, tmp2;
        // count[i, j] = count[i - 1, j] + S[i] == T[j] ? count[i - 1, j - 1] : 0
        // count[i, 0] = count[i - 1, 0] + S[i] == T[j] ? 1 : 0
        vector<int> count(n, 0); // by T
        for (int i = 0; i < m; ++i) {
            tmp1 = 1; // increment count[0] by 1 if S[i] matches T[0]
            for (int j = 0; j <= min(n - 1, i); ++j) { // count[j] == 0 when j > i
                tmp2 = tmp1;
                tmp1 = count[j];
                if (S[i] == T[j]) {
                    count[j] += tmp2;
                }
            }
        }
        return count[n - 1];
    }
};

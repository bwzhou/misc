class Solution {
public:
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
};
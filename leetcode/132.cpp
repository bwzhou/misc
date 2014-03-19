class Solution {
public:
/*
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
                if (start == end || ((start == end - 1 || pal[start + 1][end - 1]) && s[start] == s[end])) {
                    pal[start][end] = true;
                }
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
        return cost[n - 1];
    }
*/
    int minCut(string s) {
        int N = s.size();
        bool **P = new bool*[N];
        for (int i = 0; i < N; ++i) {
            P[i] = new bool[N];
            for (int j = 0; j < N; ++j) {
                P[i][j] = false;
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= N - i; ++j) {
                if (i == 1 ||
                    ((i == 2 || P[j + 1][j + i - 2]) && s[j] == s[j + i - 1])) {
                    P[j][j + i - 1] = true;
                }
            }
        }
        vector<int> M(N, N);
        for (int i = N; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (P[j][i - 1]) {
                    M[j] = min(M[j], i < N ? M[i] + 1 : 0);
                }
            }
        }
        return M[0];
    }
};

#include <string>
#include <iostream>

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

int main(int argc, char **argv) {
  cout << minCut(argv[1]) << endl;
}

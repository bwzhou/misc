#include <iostream>
#include <algorithm>
using namespace std;
string getPermutation(int n, int k) {
    string result(n, '0');
    iota(result.begin(), result.end(), '1');
    int weight  = 1;
    for (int i = 1; i < n; ++i) {
        weight *= i;
    }
    k = k - 1;
    for (int i = 0; i < n - 1; ++i) {
        if (k == 0) {
            break;
        }
        if (k / weight) {
            char c = result[i + k / weight];
            result.erase(i + k / weight, 1);
            result.insert(i, 1, c);
        }
        k = k % weight;
        weight /= n - 1 - i;
    }
    return result;
}
int main() {
    cout << getPermutation(4, 8) << endl;
    cout << getPermutation(3, 2) << endl;
}


class Solution {
public:
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
                // swap(i, i+k/weight) is wrong
                // need to move the (i+k/weight)-th character to the i-th position
                char c = result[i + k / weight];
                result.erase(i + k / weight, 1);
                result.insert(i, 1, c);
            }
            k = k % weight; // 1%1=0
            weight /= n - 1 - i; // i = n - 1 makes this div-0
        }
        return result;
    }
};
class Solution {
public:
    bool canJump(int A[], int n) {
        vector<bool> jumpable(n, false);
        int sinceLastTrue = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (A[i] >= sinceLastTrue) {
                jumpable[i] = true;
                sinceLastTrue = 0;
            }
            ++sinceLastTrue;
        }
        return jumpable[0];
    }
};
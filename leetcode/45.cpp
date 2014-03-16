class Solution {
public:
    int jump(int A[], int n) {
        vector<int> steps(n, n);
        steps[n - 1] = 0;
        deque<int> minimum;
        minimum.push_back(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            int l = 0;
            int h = minimum.size() - 1;
            while (l <= h) {
                int mid = (h - l) / 2 + l;
                if (minimum[mid] <= i + A[i]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (l < minimum.size()) {
                steps[i] = steps[minimum[l]] + 1;
            }
            while (!minimum.empty() && steps[minimum.back()] > steps[i]) {
                minimum.pop_back();
            }
            minimum.push_back(i);
        }
        return steps[0] < n ? steps[0] : -1;
    }
};
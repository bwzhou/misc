class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        int area = 0;
        stack<int> increasing;
        increasing.push(0);
        for (int i = 1; i < n; ++i) {
            while (increasing.size() > 0) {
                int t = increasing.top();
                if (height[t] > height[i]) {
                    increasing.pop();
                    area = max(area, height[t] * (i - 1 - (increasing.empty() ? -1 : increasing.top())));
                } else {
                    break;
                }
            }
            increasing.push(i);
        }
        while (increasing.size() > 0) {
            int t = increasing.top();
            increasing.pop();
            area = max(area, height[t] * (n - 1 - (increasing.empty() ? -1 : increasing.top())));
        }
        return area;
    }
};
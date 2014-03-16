class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        vector<int> histogram(matrix.size(), 0);
        int maxRec = 0;
        stack<int> bars;
        for (int j = matrix[0].size() - 1; j >= 0; --j) {
            for (int i = 0; i < matrix.size(); ++i) {
                if (matrix[i][j] == '0') {
                    histogram[i] = 0;
                } else {
                    ++histogram[i];
                }
                while (!bars.empty()) {
                    int height = histogram[bars.top()];
                    if (height > histogram[i]) {
                        bars.pop();
                        maxRec = max(maxRec, height * (i - 1 - (bars.empty() ? -1 : bars.top())));
                    } else {
                        break;
                    }
                }
                bars.push(i);
            }
            while (!bars.empty()) {
                int height = histogram[bars.top()];
                bars.pop();
                maxRec = max(maxRec, height * ((int) histogram.size() - 1 - (bars.empty() ? -1 : bars.top())));
            }
        }
        return maxRec;
    }
};
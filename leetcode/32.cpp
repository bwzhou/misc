class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left; // the stack of unmatched left
        int lastRight = -1; // the last unmatched right
        int maxLength = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                left.push(i);
            } else {
                if (left.empty()) {
                    lastRight = i;
                } else {
                    left.pop();
                    // the length of the current streak of matches starts from the last unmatched left/right
                    maxLength = max(maxLength, left.empty() ? i - lastRight : i - left.top());
                }
            }
        }
        return maxLength;
    }
};
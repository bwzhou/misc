class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for (auto each : tokens) {
            if (each == "+") {
                int rhs = s.top();
                s.pop();
                int lhs = s.top();
                s.pop();
                s.push(lhs + rhs);
            } else if (each == "-") {
                int rhs = s.top();
                s.pop();
                int lhs = s.top();
                s.pop();
                s.push(lhs - rhs);
            } else if (each == "*") {
                int rhs = s.top();
                s.pop();
                int lhs = s.top();
                s.pop();
                s.push(lhs * rhs);
            } else if (each == "/") {
                int rhs = s.top();
                s.pop();
                int lhs = s.top();
                s.pop();
                s.push(lhs / rhs);
            } else {
                s.push(atoi(each.c_str()));
            }
        }
        return s.top();
    }
};
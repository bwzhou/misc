class Solution {
public:
    bool isValid(string s) {
        map<char, char> m{ {')', '('}, {'}', '{'}, {']', '['} };
        stack<char> p;
        for (char each : s) {
            if (each == '(' || each == '{' || each == '[') {
                p.push(each);
            } else {
                if (p.empty() || p.top() != m[each]) {
                    return false;
                }
                p.pop();
            }
        }
        return p.empty();
    }
};
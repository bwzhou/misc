class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            string tmp;
            int begin = 0;
            int end = 0;
            while (begin < result.size()) {
                if (end == result.size() || result[end] != result[begin]) {
                    tmp += to_string(end - begin);
                    tmp += result[begin];
                    begin = end;
                }
                ++end;
            }
            result = tmp;
        }
        return result;
    }
};
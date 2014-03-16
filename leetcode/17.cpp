class Solution {
public:
    void gen(string answer, string digits, int start, vector<string> &letters, vector<string> &result) {
        if (start == digits.size()) {
            result.push_back(answer);
            return;
        }
        for (char c : letters[digits[start] - '2']) {
            gen(answer + c, digits, start + 1, letters, result);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> letters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        gen("", digits, 0, letters, result);
        return result;
    }
};
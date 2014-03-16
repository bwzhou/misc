class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> has;
        for (int i = 0; i < numbers.size(); ++i) {
            if (has.find(target - numbers[i]) != has.end()) {
                return {has[target - numbers[i]] + 1, i + 1};
            }
            has[numbers[i]] = i;
        }
        return {0, 0};
    }
};
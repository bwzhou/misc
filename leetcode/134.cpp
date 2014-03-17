class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        int sumfromstart = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if (sumfromstart < 0) {
                sumfromstart = 0;
                start = i;
            }
            sum += gas[i] - cost[i];
            sumfromstart += gas[i] - cost[i];
        }
        if (sum >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

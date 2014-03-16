/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int i = 0;
        int n = intervals.size();
        vector<Interval> result;
        while (i < n) {
            if (newInterval.start <= intervals[i].end) {
                break;
            }
            result.emplace_back(intervals[i]);
            ++i;
        }
        while (i < n) {
            if (newInterval.end < intervals[i].start) {
                break;
            }
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            ++i;
        }
        result.emplace_back(newInterval);
        while (i < n) {
            result.emplace_back(intervals[i]);
            ++i;
        }
        return result;
    }
};
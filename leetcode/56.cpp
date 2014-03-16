/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compareInterval(Interval i, Interval j) {
    return i.start < j.start;
}
    
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), compareInterval);
        Interval prev = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (prev.end >= intervals[i].start) {
                prev.start = min(prev.start, intervals[i].start);
                prev.end = max(prev.end, intervals[i].end);
            } else {
                result.emplace_back(prev);
                prev = intervals[i];
            }
        }
        result.emplace_back(prev);
        return result;
    }
};
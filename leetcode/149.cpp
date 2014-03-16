/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int x, int y) {
        if (x < y) return gcd(y, x);
        while (y) {
            int tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
    int maxPoints(vector<Point> &points) {
        if (points.size() == 0) {
            return 0;
        }
        if (points.size() == 1) {
            return 1;
        }
        if (points.size() == 2) {
            return 2;
        }
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int same_i = 0;
            int max_i = 0;
            map<pair<int, int>, int> count;
            for (int j = 0; j < points.size(); ++j) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                if (x == 0 && y == 0) {
                    ++same_i;
                    continue;
                } else if (x != 0 && y != 0) {
                    int g = gcd(abs(x), abs(y));
                    x /= g;
                    y /= g;
                } else if (x == 0) {
                    x = points[i].x;
                    y = 0;
                } else if (y == 0) {
                    x = 0;
                    y = points[i].y;
                }
                max_i = max(++count[make_pair(x, y)], max_i);
            }
            count.clear();
            res = max(max_i + same_i, res);
        }
        return res;
    }
};
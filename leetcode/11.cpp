class Solution {
public:
    int maxArea(vector<int> &height) { // How to come out with this great algorithm?
        int area = 0;
        int l = 0;
        int h = height.size() - 1;
        while (l < h) {
            area = max(area, min(height[l], height[h]) * (h - l));
            if (height[l] < height[h]) {
                ++l;
            } else {
                --h;
            }
        }
        return area;
    }
};
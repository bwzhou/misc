#include <iostream>

int sqrt(int x) {
    int l = 1;
    int h = x;
    while (l <= h) {
        std::cout << l << " " << h << std::endl;
        int mid = l + (h - l) / 2;
        if (mid < x / mid) {
            l = mid + 1;
        } else if (mid > x / mid) {
            h = mid - 1;
        } else {
            return mid;
        }
    }
    return h;
}

int main() {
  std::cout << sqrt(2147395599) << std::endl;
}

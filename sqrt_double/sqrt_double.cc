#include <iostream>
#include <random>
#include <cmath>

using namespace std;

double mysqrt(double N) {
  double left = min(1.0, N);
  double right = max(1.0, N);
  double mid = 0.0;
  while (abs(left-right) > 0.000001) {
    mid = (left + right) / 2;
    if (N > mid * mid) {
      left = mid;
    } else if (N < mid * mid) {
      right = mid;
    } else {
      return mid;
    }
  }
  return right;
}

int main(int argc, char **argv) {
  default_random_engine gen;
  uniform_int_distribution<int> dis(0, atoi(argv[1]));
  for (int i = 0; i < atoi(argv[2]); ++i) {
    double target = dis(gen) / 100.0;
    cout << target << " " << mysqrt(target) << " " << sqrt(target) << endl;
  }
  cout << (0.0 == 0) << endl;
  cout << (0.0000000001 == 0) << endl;
  cout << (1.00000000000 == 1) << endl;
  cout << (1.0 == 1) << endl;
}



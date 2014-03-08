#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
void primeFactors(int n) {
  while (n > 0) {
    if (n & 1) {
      break;
    }
    n >>= 1;
    cout << 2 << endl;
  }
  for (int f = 3; f < sqrt(n); f += 2) {
    while (n > 0) {
      if (n % f) {
        break;
      }
      n /= f;
      cout << f << endl;
    }
  }
  if (n > 2) {
    cout << n << endl;
  }
}
int main(int argc, char **argv) {
  primeFactors(atoi(argv[1]));
}

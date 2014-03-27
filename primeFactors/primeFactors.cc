#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
// The smallest factor of a number is always a prime factor
// Proof by contradiction: suppose the smallest factor is not
// a prime then it must contains a prime factor smaller than
// itself which controdicts the assumption that it is the
// smallest factor.
void primeFactors(int n) {
  while (n > 0) {
    if (n % 2) {
      break;
    }
    n /= 2;
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

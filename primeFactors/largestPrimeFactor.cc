#include <iostream>
#include <string>
using namespace std;
int largestPrimeFactor(long long n) {
  if (n % 2 == 0) {
    return max(2, largestPrimeFactor(n/2));
  } else {
    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        return max(i, largestPrimeFactor(n/i));
      }
    }
    return n;
  }
}

int main(int argc, char **argv) {
  cout << largestPrimeFactor(stoll(argv[1])) << endl;
}

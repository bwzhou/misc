#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
// segmented sieve: first get primes in [2, sqrt(b)] then use them to sieve primes in [a,b]
// test cases:
// -- input with range starting with prime
// -- input with range ending with prime
// -- input with range not starting with prime
// -- input with range not ending with prime
// -- input with range starting with the first prime (2)
// -- try big case 999900000 1000000000
void prime2(int a, int b) {
  bool prime[100000];
  bool range[1000000];
  for (int i = 2; i <= sqrt(b); ++i) prime[i] = true;
  for (int i = a; i <= b; ++i) range[i - a] = true;
  for (int i = 2; i <= sqrt(b); ++i) {
    if (prime[i]) {
      if (i >= a) cout << i << endl;
      for (int j = i * i; j <= sqrt(b); j += i) {
        prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= sqrt(b); ++i) {
    if (prime[i]) {
      for (int s = a/i*i; s <= b; s += i) {
        range[s - a] = false;
      }
    }
  }
  for (int i = a; i <= b; ++i) {
    if (range[i - a] && i > 1) {
      cout << i << endl;
    }
  }
  cout << endl;
}
int main() {
  int l;
  cin >> l;
  int a, b;
  for (int i = 0; i < l; ++i) {
    cin >> a >> b;
    prime2(a, b);
  }
}

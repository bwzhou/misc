/*
 * Test
 *
 * 15
 * 808
 * 2133
 * 523526236747348343262362486125986592
 * 83128
 * 1
 * 99
 * 112
 * 199
 * 999
 * 1999
 * 4572
 * 18992
 * 1000000
 * 1239999321
 * 9
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


// start from the central and compare the two halves digit by digit, add 1 to
// LSD of the first half when it is not larger than the second half.
string nextPalin(const string &num) {
  bool larger = false;
  int n = (int) num.size();
  int left = (n - 1) / 2;
  int right = n / 2;
  for (int i = left, j = right; i >= 0 && j < n; --i, ++j) {
    if (num[i] < num[j]) {
      break;
    }
    if (num[i] > num[j]) {
      larger = true;
      break;
    }
  }
  string half;
  if (larger == false) {
    char carry = 1;
    for (int i = left; i >= 0 || carry > 0; --i) {
      char digit = i >= 0 ? num[i] - '0' : 0;
      half.push_back((digit + carry) % 10 + '0');
      carry = (digit + carry) / 10;
    }
  } else {
    for (int i = left; i >= 0; --i) {
      half.push_back(num[i]);
    }
  }
  string res = half;
  reverse(res.begin(), res.end());
  // adjust for duplicated center for odd number digits.
  if (left == right) {
    res = res.substr(0, res.size() - 1);
  }
  // adjust for all-9 digits.
  // must to balance the adjustment to keep the result a palindrome.
  // '9' would result in '01' if only adjust the first half.
  if (half.size() > (n + 1) / 2) {
    half = half.substr(1);
  }
  res += half;
  return res;
}

void add0(string &num) {
  for (int i = 0; i < num.size(); ++i) {
    num[i] += '0';
  }
}

void sub0(string &num) {
  for (int i = 0; i < num.size(); ++i) {
    num[i] -= '0';
  }
}

void add1(string &num, int end) {
  char carry = 1;
  for (int i = end; i >= 0 && carry > 0; --i) { // without carry>0 the function becomes linear the program becomes O(n^2)
    char sum = num[i] + carry;
    num[i] = sum % 10;
    carry = sum / 10;
  }
  if (carry == 1) {
    num = char(1) + num;
  }
}

// for every i in [0, n-1] and its mirror index n-1-i:
// if num[i] > num[n-1-i] let num[n-1-i]=num[i];
// if num[i] < num[n-1-i] let num[n-1-i]=num[i], then add '1' to n-2-i.
// Invariant post each iteration:
//  a) num[0, i]==num[n-1, n-1-i];
//  b) num only becomes greater.
string& nextPalin2(string &res) {
  sub0(res);
  add1(res, res.size() - 1); // res.size() may change here
  int l = res.size();
  int i = 0;
  while (i < l) {
    if (res[i] > res[l - i - 1]) {
      res[l - i - 1] = res[i];
      ++i;
    } else if (res[i] < res[l - i - 1]) {
      add1(res, l - i - 2);
      res[l - i - 1] = 0;
    } else {
      ++i;
    }
  }
  add0(res);
  return res;
}

int main() {
  int l;
  cin >> l;
  string e;
  for (int i = 0; i < l; ++i) {
    cin >> e;
    //cout << nextPalin(e) << endl;
    cout << nextPalin2(e) << endl;
  }
}

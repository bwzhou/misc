#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::string;
using std::reverse;

class BigInt {
public:
  BigInt(int sign, int size) : sign_(sign), digits_(size) {
  }
  explicit BigInt(const string &s) : sign_(s[0] == '-' ? -1 : 1) {
    for (const char &c : s) {
      if (c >= '0' && c <= '9') {
        digits_.push_back(c - '0');
      }
    }
    reverse(digits_.begin(), digits_.end());
  }
  BigInt operator*(const BigInt &rhs) {
    int sign = sign_ * rhs.sign_;
    BigInt result(sign, (sign == -1) + digits_.size() + rhs.digits_.size());
    int i, j;
    for (i = 0; i < rhs.digits_.size(); ++i) {
      int carry = 0;
      for (j = 0; j < digits_.size() || carry; ++j) {
        int digit = result.digits_[i + j] +
                    (j < digits_.size() ? digits_[j] * rhs.digits_[i] : 0) +
                    carry;
        result.digits_[i + j] = digit % 10;
        carry = digit / 10;
        //cout << carry << endl;
        //result.print();
      }
    }
    if (digits_.size() == 1 && digits_.back() == 0 ||
        rhs.digits_.size() == 1 && rhs.digits_.back() == 0) {
      result.digits_.resize(1);
      result.sign_ = 1;
    } else {
      result.digits_.resize(i + j - 1);
    }
    return result;
  }
  void print() {
    if (sign_ == -1)
      cout << '-';
    copy(digits_.rbegin(), digits_.rend(), ostream_iterator<int>(cout, ""));
    cout << endl;
  }
private:
  vector<char> digits_;
  int sign_;
};

int main(int argc, char **argv) {
  BigInt a(argv[1]), b(argv[2]);
  (a*b).print();
  return 0;
}

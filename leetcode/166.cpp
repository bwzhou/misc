class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string decimal;
        map<int, int> known;
        string result;
        if (numerator > 0 && denominator < 0 ||
            numerator < 0 && denominator > 0) {
            result += "-";
        }
        long long n = llabs(numerator);
        long long m = llabs(denominator);
        result.append(to_string(n / m));
        n %= m;
        if (n) {
            result.push_back('.');
        }
        int left;
        while (n) {
            if (known.find(n) != known.end()) {
                left = known[n];
                break;
            }
            known[n] = decimal.size();
            decimal.push_back(n * 10 / m + '0');
            n = n * 10 % m;
        }
        for (int i = 0; i < decimal.size(); ++i) {
            if (n && left == i) {
                result.push_back('(');
            }
            result.push_back(decimal[i]);
        }
        if (n) {
            result.push_back(')');
        }
        return result;
    }
};

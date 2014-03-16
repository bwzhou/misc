class Solution {
public:
    string romanOf(int n, char ten, char five, char one) {
        switch (n) {
            case 1: return string(1, one);
            case 2: return string(2, one);
            case 3: return string(3, one);
            case 4: return string(1, one) + string(1, five);
            case 5: return string(1, five);
            case 6: return string(1, five) + string(1, one);
            case 7: return string(1, five) + string(2, one);
            case 8: return string(1, five) + string(3, one);
            case 9: return string(1, one) + string(1, ten);
            default: return "";
        }
    }
    string intToRoman(int num) {
        string result;
        result += romanOf(num / 1000, ' ', ' ', 'M');
        num %= 1000;
        result += romanOf(num / 100, 'M', 'D', 'C');
        num %= 100;
        result += romanOf(num / 10, 'C', 'L', 'X');
        num %= 10;
        result += romanOf(num, 'X', 'V', 'I');
        return result;
    }
};
class Solution {
public:
    string ones[20] = {"",         " One",       " Two",      " Three",
                       " Four",    " Five",      " Six",      " Seven",
                       " Eight",   " Nine",      " Ten",      " Eleven",
                       " Twelve",  " Thirteen",  " Fourteen", " Fifteen",
                       " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string tens[10] = {"",       " Ten",   " Twenty",  " Thirty", " Forty",
                       " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};

    string solve(int num) {
        if (num < 20) {
            return ones[num];
        } else if (num < 100) {
            return tens[num / 10] + solve(num % 10);
        } else if (num < 1000) {
            return solve(num / 100) + " Hundred" + solve(num % 100);
        }
        for (int i = 3; i >= 0; i--) {
            if (num >= pow(1000, i)) {
                return solve(num / pow(1000, i)) + thousands[i] +
                       solve(num % (int)pow(1000, i));
            }
        }
        return "";
    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return solve(num).substr(1);
    }
};
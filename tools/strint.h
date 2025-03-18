#pragma once

#include <string>

using std::string;
using std::reverse;

// If the input is invalid, return 0 without throwing an exception (!)
// "---+-323" is valid, but "-232-3" is not valid

inline bool isCharNum(char character) {
    return '0' <= character && character <= '9';
}

int strint(const string& str) {
    
    if (str.empty()) return 0;

    int result = 0, sign = 1, i = 0;

    while (i < str.size() && !isCharNum(str[i])) {
        if (str[i] == '-') sign *= -1;
        else if (str[i] != '+') return 0;
        ++i;
    }

    if (str.size() - i > 10) return 0; // Prevent overflow

    for (; i < str.size(); ++i) {
        if (!isCharNum(str[i])) return 0;
        result = result * 10 + (str[i] - '0');
    }

    return result * sign;
}

// "-1" is valid
// Handles numbers from "-2147483648" to "2147483647"

string intstr(int num) {
    
    if (num == 0) return "0";
    if (num == -2147483648) return "2147483647"; // Absolute value

    string result;
    bool isNegative = (num < 0);

    if (isNegative) num = -num;

    result.reserve(10);
    
    do {
        result += (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNegative) result += '-';

    reverse(result.begin(), result.end());
    return result;
}

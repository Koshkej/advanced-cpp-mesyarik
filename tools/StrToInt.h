#ifndef STR_TO_INT_H
#define STR_TO_INT_H

#include <string>
#include <stdexcept>

using std::string;
using std::reverse;

// For invalid_argument return 0 without throw (!)
// "---+-323" is valid, but "-232-3" is not valid

bool isCharNum(char character) {

	return (character >= '0' && character <= '9');
}

int strToInt(string str) {

	if (str.empty()) return 0;

	int result = 0, sign = 1, i = 0;

	while (i < str.size() && !isCharNum(str[i])) {
		
		if (str[i] == '-') sign *= -1;
		else if (str[i] != '+') return 0;

		++i;
	}

	if (str.size() - i > 10) return 0;

	for (; i < str.size(); ++i) {

		if (!isCharNum(str[i])) return 0;

		result = result * 10 + (str[i] - '0');
	}

	return result * sign;
}

// "-1" is valid
// from "-2147483648" to "2147483647"

string intToStr(int num) {

	if (num == 0) return "0";
	if (num == -2147483648) return "2147483647";

	string result = "";
	bool isNegative = false;

	if (num < 0) isNegative = true, num *= -1;

	result.reserve(10);

	do {

		result += num % 10 + '0';
		num /= 10;

	} while (num > 0);

	if (isNegative) result += '-';

	reverse(result.begin(), result.end());

	return result;
}

#endif // STR_TO_INT_H
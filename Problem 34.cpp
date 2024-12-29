//Problem 34
//URL: https://leetcode.com/problems/string-to-integer-atoi/submissions/1480866053/
//Level: Med
//Last updated: 2024/12/17
/*Description: According to this problem, we have to turn the number in a string into an integer.
The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached.
If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. 
Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

Return the integer as the final result.
Example:    

Example 1:
Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)

Example 2:
Input: s = ""1337c0d3""
Output: 1337

Example 3:
Input: s = "world 2024"
Output: "0"

Solution in C++ language
 */
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        while (s[i] == ' ') 
            i++;

        if (i == n) 
            return 0;

        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long long result = 0;
        while ('0' <= s[i] && s[i] <= '9' && i < n) {
            result = result * 10 + (s[i] - '0');
            if (sign * result > INT_MAX) result = INT_MAX;
            if (sign * result < INT_MIN) result = pow(2, 31);
            i++;
        }

    return sign * result;
    }
};

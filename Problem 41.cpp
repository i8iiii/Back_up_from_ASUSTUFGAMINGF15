//Problem 41
//URL: https://leetcode.com/problems/roman-to-integer/
//Level: Easy
//Last updated: 2024/12/20
/*Description: According to this problem, we have to convert roman number to latin integer number.
Example:    

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.                   
                                        
Example 2:
Input: s = "MCVII"
Output: 1107

Example 3:
Input: s = "XXIV"
Output: 24

Solution in C++ language
 */
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V' || s[i + 1] == 'X')
                    sum -= 1;
                else 
                    sum += 1;
            } 

            if (s[i] == 'V')
                sum += 5;

            if (s[i] == 'X') {
                if (s[i + 1] == 'L' || s[i + 1] == 'C' || s[i + 1] == 'C' || s[i + 1] == 'D' || s[i + 1] == 'M')
                    sum -= 10;
                else 
                    sum += 10;
            }

            if (s[i] == 'L')
                sum += 50;

            if (s[i] == 'C') {
                if (s[i + 1] == 'D' || s[i + 1] == 'M')
                    sum -= 100;
                else 
                    sum += 100;
            }

            if (s[i] == 'D')
                sum += 500;

            if (s[i] == 'M')
                sum += 1000;
        }

    return sum;
    }
};
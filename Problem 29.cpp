//Problem 29
//URL: https://leetcode.com/problems/palindrome-number/description/
//Level: Easy
//Last updated: 2024/12/15
/*Description: According to this problem, we have to check if a number is a palindrome number (12321, 121, etc).
Example:    

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = 232
Output: false
Explanation: -232 cannot be read as 23-2 from left to right and from right to left.

Example 3:
Input: x = 0
Output: true
Explanation: 0 reads as 0 from left to right and from right to left.
Solution in C++ language
 */
class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    else {
        int temp1 = x;
        int temp2 = x;
        long long digit, tempDigit , tempCounter;
        long long sum = 0;
        int counter = 1;

        while (temp1 / float(10) >= 1) {
            counter += 1;
            temp1 /= 10;
        }

        tempCounter = counter;

        for (int i = 0; i < counter; i++) {
            digit = temp2 % 10;
            temp2 /= 10;
            tempDigit = digit;

            for (int j = 1; j < tempCounter; j++) {
                tempDigit *= 10;
            }

            tempCounter -= 1;
            sum += tempDigit; 
        }
        if (sum - x == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    }
};
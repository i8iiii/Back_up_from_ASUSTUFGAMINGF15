//Problem 12
//URL: https://leetcode.com/problems/happy-number/
//Level: Easy
//Last updated: 2024/11/17
//Description: According to this problem, we have to calculate the sum of digits of the input number until it equal to 1.
/*Example:      
Example 1:
                Input: n = 19
                Output: true
                Explanation:
                1^2 + 9^2 = 82
                8^2 + 2^2 = 68
                6^2 + 8^2 = 100
                1^2 + 0^2 + 0^2 = 1
Example 2:
                Input: n = 10
                Output: true
                Explanation:
                1^2 + 0^2 = 1
Example 3:
                Input: n = 10
                Output: false

*/
//Solution in C++ language
class Solution {
public:
    bool isHappy(int n) {
        int temp = n, digit;
        int cnt = 0;
        int sum = 0;

        while (sum != 1) {
            sum = 0;
            while(temp) {
                digit = temp % 10;
                temp /= 10;
                sum += (digit * digit);
            }
            temp = sum;
            cnt++;
            if (cnt > 10)
                return false;
        }   

    return true;

    }
};
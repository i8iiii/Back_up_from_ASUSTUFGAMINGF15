//Problem 10
//URL: https://leetcode.com/problems/plus-one/
//Level: Easy
//Last updated: 2024/11/17
//Description: According to this problem, we have to plus one into the number in the array given
/*Example:

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,4,2,1]
Output: [4,4,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4421 + 1 = 4422.
Thus, the result should be [4,4,2,2].

Example 3:
Input: digits = [8,9]
Output: [9,0]
Explanation: The array represents the integer 89.
Incrementing by one gives 89 + 1 = 90.
Thus, the result should be [9,0].

*/
//Solution in C++ language
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] + 1 < 10) {
                digits[i] += 1;
                break;
            } else if (digits[i] + 1 >= 10) {
                digits[i] += 1;
                digits[i] /= 10;
                digits.push_back(0);
                if (i > 0) {
                    digits[i] = 0;
                    digits.pop_back();
                }
            }
        }
        return digits;
    }
};

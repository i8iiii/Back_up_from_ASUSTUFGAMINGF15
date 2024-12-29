//Problem 21
//URL: https://leetcode.com/problems/length-of-last-word/?envType=problem-list-v2&envId=string
//Level: Easy
//Last updated: 2024/11/25
/*Description: According to this problem, we find the length of the last word of a string.
/*Example:    

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "you       are my         world       "
Output: 5
Explanation: The last word is "World" with length 5.

Example 3:
Input: s = "a "
Output: 1
Explanation: The last word is "a" with length 1.
*/
//Solution in C++ language
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        if (n == 1 && isalpha(s[0])) return 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                s.pop_back();
            } else {
                count++;
            }
            if (s[i] == ' ')
                return count;
        }
    return count;
    }
};
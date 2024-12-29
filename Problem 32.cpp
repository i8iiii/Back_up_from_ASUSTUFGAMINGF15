//Problem 32
//URL: https://leetcode.com/problems/longest-palindromic-substring/
//Level: Med
//Last updated: 2024/12/16
/*Description: According to this problem, we have to print out the longest palindrome substring in the given string.
Example:    

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "aaaa"
Output: "aaaa"

Example 3:
Input: s = "ac"
Output: "a"
Explanation: "c" is also a valid answer.
Solution in C++ language
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int length = 0;
        int save = 0;
        string res = "";

        if (n == 1) return s;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i ; j--) {
                if (s[i] != s[j]) {
                    continue;
                } else {
                    
                    bool isPalindrome = true;
                    int left = i, right = j;
                    while (left < right) {
                        if (s[left] != s[right])
                            isPalindrome = false;
                        left++;
                        right--;
                    }

                    if (isPalindrome && length < j - i + 1) {
                        length = j - i + 1;
                        save = i;

                    }
                }
            }
        }

        if (length == 0)
            res += s[0];

        for (int i = save; i < save + length; i++) {
            res += s[i];
        }
        
    return res;
    }
};
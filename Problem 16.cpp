//Problem 16
//URL: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
//Level: Easy
//Last updated: 2024/11/19
/*Description: According to this problem, we have to find the index of the target in given array, if we can't find the target number, 
we have to find where it should be put.*/
/*Example:    

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "hello", needle = "ll"
Output: 2
Explanation: "ll" occurs at index 2.
The first occurrence is at index 2, so we return 2.

Example 3:
Input: haystack = "skibidi", needle = "sigma"
Output: -1
Explanation: "sigma" did not occur in "skibidi", so we return -1.
*/

//Solution in C++ language
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        bool flag;
        if (n > m) {
            return -1;
        }
        for (int i = 0; i < m; i++) {
            int a = 0;
            flag = true;
            for (int j = i; j < n; j++) {
                if (needle[a] != haystack[j]) {
                    flag = false;
                }
                a++;
            }
            if (flag == true) {
                return i;
            } 
            n++;
            if (n > m) return -1;
        }
    return -1;
    }
};
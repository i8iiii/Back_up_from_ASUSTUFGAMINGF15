//Problem 40
//URL: https://leetcode.com/problems/find-the-difference/?envType=problem-list-v2&envId=string
//Level: Easy
//Last updated: 2024/12/19
/*Description: According to this problem, we are given a string s, and then we gerenate a string t from s with random order.
After that, we add a character into string t and print out that character.
Example:    

Example 1:
Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.                    
                                        
Example 2:
Input: s = "ac", t = "aca"
Output: "a"

Example 3:
Input: s = "", t = "k"
Output: "k"

Solution in C++ language
 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0, sum2 = 0;
        int i = 0, j = 0;
        
        while (i < s.length()) {
            sum1 += (s[i] - 'a');
            i++;
        } 
        while (j < t.length()) {
            sum2 += (t[j] - 'a');
            j++;
        }
        
    return ('a' + (sum2 - sum1));
    }
};
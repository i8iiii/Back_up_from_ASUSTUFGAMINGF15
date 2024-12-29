//Problem 39
//URL: https://leetcode.com/problems/reverse-string/
//Level: Easy
//Last updated: 2024/12/19
/*Description: According to this problem, we have to print out the reverse string of the given string.
Example:    

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]                     
                                        
Example 2:
Input: s = ["b","a","n","a","n","a"]             
Output: ["a","n","a","n","a","b"]

Example 3:
Input: s = ["s","k","i","b","i","d","i"]              
Output: ["i","d","i","b","i","k","s"]

Solution in C++ language
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        vector<char>& temp = s;
        for (int i = n - 1; i >= 0; i--) {
            s.push_back(temp[i]);
        }
        s.erase(s.begin(), s.begin() + n);
    }
};
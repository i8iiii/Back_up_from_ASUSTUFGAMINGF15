//Problem 18
//URL: https://leetcode.com/problems/longest-common-prefix/description/
//Level: Easy
//Last updated: 2024/11/24
/*Description: According to this problem, we find the longest common prefix of an array of strings, if there is no common prefix, 
then return an empty string.

/*Example:    

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
Explanation: Because the longest common prefix here is "fl", so print out "fl".

Example 2:
Input: strs = ["dog","cat","bird"]
Output: ""
Explanation: Because there is no common prefix among these strings, so print out an empty string.

Example 3:
Input: strs = ["flower","flower","flower"]
Output: "flower"
Explanation: Because the longest common prefix here is "flower", so print out "flower".
*/

//Solution in C++ language
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        long long count, x = 0;
        char prefix[10000] = {0};
        for (long long i = 0; i < strs[0].size(); i++) {
            count = 0;
            for (long long j = 0; j < n; j++) { 
                if (strs[0][i] == strs[j][i])
                    count++;
                else return prefix;
                if (count == n)
                    prefix[x] = strs[j][i];
            }
            cout << prefix << " ";
            x++;
        }
    return prefix;
    }
};
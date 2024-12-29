//Problem 38
//URL: https://leetcode.com/problems/add-binary/?envType=problem-list-v2&envId=string
//Level: Easy
//Last updated: 2024/12/19
/*Description: According to this problem, we have to do the binary addition and return a string reveal the result.
Example:    

Example 1:
Input: a = "11", b = "1"                
Output: "100"
Explanation: 1 + 1 = 2 (2 mod 2 = 0) --> 0,  carry 1 (2 div 2 = 1)
             1 + carry  = 2 --> 0, carry 1
             the last carry is one and there is no digit needs to be added, so we write down 1.
             then we got 100.                     
                                        
Example 2:
Input: a = "11111", b = "100"                
Output: ""100011""

Example 3:
Input: a = "01", b = "10"                
Output: "11"

Solution in C++ language
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int na = a.size();
        int nb = b.size();
        int i = na - 1, j = nb - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += (a[i] - '0');
            if (j >= 0) sum += (b[j] - '0');
            carry = (sum / 2); 
            res += (sum % 2 + '0');
            i--;
            j--;
        }
    
        reverse(res.begin(), res.end());
    return res;
    }
};
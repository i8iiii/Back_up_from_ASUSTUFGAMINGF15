//Problem 3
//URL: https://www.hackerrank.com/challenges/c-tutorial-strings/problem?isFullScreen=true
//Level: Easy
//Last updated: 2024/11/17
/*Description: According to the request of the problem, we have to print out the length of two strings
and exchange the first character of them to each other.*/
/*Example:
Example 1:
Sample Input
    abcd
    ef
Sample Output
    4 2
    abcdef
    ebcd af
Explanation:
    The length of string "abcd" is 4, and "ef" is 2.
    The concatenation of "abcd" and "ef" is "abcdef".
    "e" is combined with "bcd", "a" is combined with "f". Thus, "ebcd af" is printed.
Example 2:
Input:
    abc
    xyz
Output:
    3 3
    abcxyz
    xbc ayz
Explanation:
    The length of string "abc" is 3, and "xyz" is 3.
    The concatenation of "abc" and "xyz" is "abcxyz".
    "x" is combined with "bc", "a" is combined with "yz". Thus, "xbc ayz" is printed.
Example 3:
Input:
    apple
    banana
Output:
    5 6
    applebanana
    bpple anana
Explanation:
    The length of string "apple" is 4, and "banana" is 2.
    The concatenation of "apple" and "banana" is "applebanana".
    "b" is combined with "pple", "a" is combined with "anana". Thus, "bpple anana" is printed.
*/
//Solution in C++ language
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    string a, b;
    cin >> a >> b;

    cout << a.length() << " " << b.length() << endl;
    cout << a + b << endl;  

    string c = a.substr(1);
    string d = b.substr(1);

    cout << b[0] + c << " " << a[0] + d;

    return 0;
}

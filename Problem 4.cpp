//Problem 4
//URL: https://www.hackerrank.com/challenges/cpp-input-and-output/problem?isFullScreen=true
//Level: Easy
//Last updated: 2024/11/17
//Description: This problem can be solved by calculating the total of all three numbers.
/*Example:
Example 1:
Sample Input:   1 2 7
Sample Output:  10
Explanation:    The sum of the three numbers is 1 + 2 + 7 = 10.

Example 2:
Input:          10 6 5
Output:         21
Explanation:    The sum of the three numbers is 10 + 6 + 5 = 21.

Example 3:
Input:          3 6 1
Output:         10
Explanation:    The sum of the three numbers is 3 + 6 + 1 = 10.
*/
//Solution is C++ language
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a; int b; int c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    cout << sum;  
    return 0;
}
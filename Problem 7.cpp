//Problem 7
//URL: https://www.hackerrank.com/challenges/c-tutorial-pointer/problem?isFullScreen=true
//Level: Easy
//Last updated: 2024/11/18
/*Description: To solve this problem, use pointer to write a program that calculate the sum of 2 intergers x and y, 
and the absoluted difference of them.*/
/*Example:
Example 1:
Sample Input:
    4
    5
Sample Output:
    9
    1
Explanation:
    4 + 5 = 9
    |4 - 5| = 1

Example 2:
Input:
    10
    10
Output:
    20
    0
Explanation:
    10 + 10 = 20
    |10 - 10| = 0

Example 3:
Input:
    12
    9
Output:
    21
    3
Explanation:
    12 + 9 = 21
    |12 - 9| = 3

*/
//Solution in C++ language
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sum(int x, int y) {
    int *a = &x;
    int *b = &y;
    (*a) += (*b);
    return (*a);
}
int substract(int x, int y) {
    int *a = &x;
    int *b = &y;
    (*a) -= (*b);
    if ((*a) < 0) {
        (*a) *= -1;
    }
    return (*a);
}
int main() {
    int x, y;
    cin >> x >> y;
    cout << sum(x, y) << endl;
    cout << substract(x, y);
    return 0;
}


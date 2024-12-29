//Problem 9
//URL: https://www.hackerrank.com/challenges/arrays-introduction/problem?isFullScreen=true
//Level: Easy
//Last updated: 2024/11/17
//Description: To solve this problem, i can just print out the the array in the reversed index
/*Example:
Example 1:
Sample Input:
4
1 4 3 2
Sample Output:
2 3 4 1

Example 2:
Input:
7
1 4 3 6 8 6 9
Output:
9 6 8 6 3 4 1 

Example 3:
Input:
8
1 2 8 6 54 3 5 10
Output:
10 5 3 54 6 8 2 1 

*/
//Solution in C++ language
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }   
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}

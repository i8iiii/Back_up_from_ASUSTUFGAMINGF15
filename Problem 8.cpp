//Problem 8
//URL: https://www.hackerrank.com/challenges/vector-sort/problem?isFullScreen=true
//Level: Easy
//Last updated: 2024/11/18
//Description: To solve this problem, use vector to sort from the least to the largest number in the given array.
/*Example:
Example 1:
Sample Input:
5
1 6 10 8 4
Sample Output:
1 4 6 8 10
Explanation:    Sorting from the least to the largest number in the given array:
                            1 6 10 8 4 ---->  1 4 6 8 10
Example 2:
Input:
10
1 6 10 8 4 9 9 1 8 7
Output:
1 1 4 6 7 8 8 9 9 10 
Explanation:    Sorting from the least to the largest number in the given array:
                        1 6 10 8 4 9 9 1 8 7 ---->  1 1 4 6 7 8 8 9 9 10 
Example 3:
Input:
19
1 3 4 2 6 7 88 9 1 3 4 5 6 11 23 44 8 0 19 
Output:
0 1 1 2 3 3 4 4 5 6 6 7 8 9 11 19 23 44 88 
Explanation:    Sorting from the least to the largest number in the given array:
    1 3 4 2 6 7 88 9 1 3 4 5 6 11 23 44 8 0 19  ---->  0 1 1 2 3 3 4 4 5 6 6 7 8 9 11 19 23 44 88 

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
    int a;
    vector<int> container;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        container.push_back(a);
    }    
    
    sort(container.begin(), container.end());
    
    for (int i = 0; i < n; i++)
        cout << container[i] << " ";
        
    return 0;
}
//Problem 6
//URL: https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem?isFullScreen=true
//Level: Easy
//Last updated: 2024/11/18
/*Description: This problem can be solved by using if, else to print out the english letter of numbers from 1 - 9,
and print out "Greater than 9" if the number is greater than 9 */
/*Example:
Example 1:
Sample Input:   5
Sample Output:  five
Explanation:    five is the English word for the number.

Example 2:
Input:          10
Output:         Greater than 9
Explanation:    10 is greater than 9 --> print out "Greater than 9".

Example 3:
Input:          45
Output:         Greater than 9
Explanation:    45 is greater than 9 --> print out "Greater than 9".
*/
//Solution is C++ language
#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a == 1){
        cout << "one";
    }
    else if (a == 2)
    {
        cout << "two";
    }
    else if (a == 3){
        cout << "three";
    }
    else if (a == 4)
    {
        cout << "four";
    }
    else if (a == 5)
    {
        cout << "five";
    }
    else if ( a == 6)
    {
       cout << "six";
    } 
    else if ( a == 7)
    {
       cout << "seven";
    } 
    else if (a == 8)
    {
        cout << "eight";
    }
    else if(a == 9)
    {
        cout << "nine";
    }
    else {
        cout << "Greater than 9";
    }
}


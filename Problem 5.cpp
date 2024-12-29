//Problem 5
//URL: https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem?isFullScreen=true
//Level: Easy
//Last updated: 2024/11/17
/*Description: This problem can be solved by using if, else to print out the english letter of numbers from 1 - 9,
and print out "even" if the number is a even number and greater than 9 (it's the same with the odd numbers that is greater than 9)*/
/*Example:

Example 1:
Sample Input:
        8 11
Sample Output:
        eight
        nine
        even
        odd
Explanation:
    The numbers 8 to 9 are printed as their English word equivalents.
    The number 10 is greater than 9 and is even, so the word "even" is printed.
    The number 11 is greater than 9 and is odd, so the word "odd" is printed.

Example 2:
Input:
        5 15
Output:
        five
        six
        seven
        eight
        nine
        even
        odd
        even
        odd
        even
        odd
Explanation:
    The numbers 5 to 9 are printed as their word equivalents ("five", "six", "seven", "eight", "nine").
    The numbers from 10 to 15 are printed as "even" for even numbers (10, 12, 14) and "odd" for odd numbers (11, 13, 15).

Example 3:
Input:

        8 18
Output:
        eight
        nine
        even
        odd
        even
        odd
        even
        odd
        even
Explanation:
The numbers 8 and 9 are printed as their word equivalents.
The numbers from 10 to 18 are checked for even or odd and printed accordingly.

*/
//Solution is C++ language
#include <iostream>

using namespace std;
int main() {
    int a; int b;
    cin >> a >> b;
    for (int i = a; i <= b;i++)
    {
    if (i == 1){
        cout << "one"<< endl;
    }
    else if (i ==2)
    {
        cout << "two"<< endl;
    }
    else if (i==3){
        cout << "three"<< endl;
    }
    else if (i==4)
    {
        cout << "four"<< endl;
    }
    else if (i==5)
    {
        cout << "five" << endl;
    }
    else if ( i==6)
    {
       cout << "six" << endl;
    } 
    else if ( i==7)
    {
       cout << "seven"<< endl;
    } 
    else if (i==8)
    {
        cout << "eight"<< endl;
    }
    else if(i==9)
    {
        cout << "nine"<< endl;
    }
    else if ((i > 9) && (i%2==0)) 
    {
        cout << "even"<< endl;
    }
    else if ((i > 9) && (i%2!=0))
        cout << "odd" << endl;
    }
    return 0;
}

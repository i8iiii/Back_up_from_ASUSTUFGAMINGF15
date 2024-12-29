//Problem 2
//URL: https://www.hackerrank.com/challenges/c-tutorial-functions/problem?isFullScreen=true
//Level: Easy
//Last updated: 2024/11/17
//Description: To solve this problem, i find the max element in array by using for loops and return the max element
/*Example: 
    1.          Sample Input:   3 4 6 5
                Sampple Output: 6
        Explaination: the max number of these four numbers is 6, so the output is 6

    2.          Input: 2 4 1 10
                Output: 10
        Explaination: the max number of these four numbers is 10, so the output is 10

    3.          Input: 7 8 1 2
                Output: 8 
        Explaination: the max number of these four numbers is 8, so the output is 8
*/
//Solution in C++ language
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int greatestNum() {
    int chuoi_so[4];
    int res = 0;

    for (int i = 0; i < 4; i++) {
        cin >> chuoi_so[i];
    } 

    for ( int j = 0; j < 4;j++) {
        if (res < chuoi_so[j]) {
            res = chuoi_so[j];
        }
    } 
    return res;
}

int main() {
    
    cout << greatestNum();

    return 0;
}





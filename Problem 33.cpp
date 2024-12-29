//Problem 33
//URL: https://codeforces.com/contest/2044/problem/B
//Level: Easy
//Last updated: 2024/12/17
/*Description: According to this problem, we have to print out the string include only 'q', 'p' and 'w' but it will appear like
the way we look at that string but from the other side of the glass. (qwq --> pwp)
Example:    
Example 1:
Input: 
5
qwq
ppppp
pppwwwqqq
wqpqwpqwwqp
pqpqpqpq

Output: 
pwp
qqqqq
pppwwwqqq
qpwwpqwpqpw
pqpqpqpq

Example 2:
Input: 
1
wwwwww
Output: 
wwwwww

Example 3:
Input: 
3
wpqpwp
pppp
qwwp
Output: 
qwqpqw
qqqq
qwwp

Solution in C++ language
*/
#include<iostream>
#include<cstring>

using namespace std;

void mirrorString(char a[]) {
    int n = strlen(a);
    int count = 0;
    char res[100];
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 'q') 
            res[count] = 'p';
        else if (a[i] == 'p') 
            res[count] = 'q';
        else 
            res[count] = 'w';
        count++;
    } 
    res[n] = '\0';
    cout << res;
    cout << endl;
}

int main() {
    char input[100][1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        mirrorString(input[i]);
    }
    return 0;
}
#include<iostream>
#include<cstring>

using namespace std;

int main() {
    char str[] {"123453432456"};
    long long a = strtoll(str, NULL, 10);
    cout << a;
    return 0;
}
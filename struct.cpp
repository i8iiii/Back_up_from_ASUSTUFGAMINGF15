#include<iostream>
#include<cmath>
#include<cstring>
#include<fstream>

using namespace std;

struct fraction {
    int num;
    int deno;
};

void input(fraction &frac) {
    cout << "Input a numertor: ";
    cin >> frac.num;
    do {
        cout << "Input a denominator (!= 0): ";
        cin >> frac.deno;
    } while (frac.deno == 0);
}

int GCD(int a, int b) {
    int temp;
    while (a % b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return temp;
}

int main() {

    fraction frac1, frac2, frac3;
    input(frac1); input(frac2);
    int a = frac1.num * frac2.deno;
    int b = frac1.deno * frac2.num;
    frac3.num = a + b;
    frac3.deno = frac1.deno * frac2.deno;
    if (frac3.num % frac3.deno == 0) {
        cout << "The solution is: " << frac3.num / frac3.deno;
    } else {
        cout << "The solution is: " << frac3.num / GCD(frac3.num, frac3.deno) << " / " << frac3.deno / GCD(frac3.num, frac3.deno);
    }
    return 0;
}
#include<iostream>
#include<cmath>

using namespace std;

int main () {
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    int *l = new int[n]{1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                l[i] = max(l[i], l[j] + 1);
            }
        }
    }
    int m = l[0];
    for (int i = 0; i < n; i++)
        if (m < l[i])
            m = l[i];
    cout << m;
    delete[]a;
    delete[]l;
    return 0;
}
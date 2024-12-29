#include<iostream>
#include<cmath>

using namespace std;

int GCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        int mod = a % b;
        a = b; 
        b = mod;
    }
    return a;
}

int GcdOfArray(int *arr, int n) {
    while (n > 1) {
        for (int i = 0; i < n / 2; i++) {
            arr[i] = GCD(arr[2 * i], arr[2 * i + 1]);
            if (n % 2 != 0)
                arr[n / 2] = arr[n - 1];
            n = (n + 1) / 2; 
        }
    }
    return arr[0];
}

int CheckArr(int *arr, int n) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[i + 1]) 
            x++;
        else    
            break;
    }

    int count = 0;
    for (int i = x; i < n - 1; i++) {
        if (arr[i] < arr[i + 1])
            return false;
        count++;
    }

    if (count == 0 || x == 0) return false;
    return true;
}

void generateMatrix1 (int **&a, int length, int width) { 
    a = new int* [length];

    for (int i = 0; i < length; i++) {
        a[i] = new int[width];
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            std::cin >> a[i][j];
        }
    }
}

void findMaxScore(int **P, int n, int m) {
    int *index = new int[n];
    int maxScore = 0;
    int k = 0;
    int AVGS = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            AVGS += P[i][j];

        index[k] = AVGS;
        k++;

        if (maxScore < AVGS) {
            maxScore = AVGS;
        }
        AVGS = 0;
    }

    for (int i = 0; i < k; i++) {
        if (index[i] == maxScore)
            cout << i << " ";
    }

    delete []index;
}



int main() {
    int n, m;
    cin >> n >> m;
    int **a;
    generateMatrix1(a, n, m);
    findMaxScore(a, n, m);
    delete []a;
    return 0;
}
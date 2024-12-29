#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

int main() {
    int a, k;
    int arr[100];
    
    fstream fIn;
    fIn.open("new.txt", ios::in);
    fIn >> a >> k;
    for (int i = 0; i < a; i++) {
        fIn >> arr[i];
    }
    fIn.close();

    fstream f0ut;
    f0ut.open("new.txt", ios::out | ios::app); 
    int count = 0;
    for (int i = 0; i < a; i++) {
        if (k == arr[i]) {
            count++;
        } 
    }
    f0ut << "So " << k << " xuat hien " << count << " lan.";
    f0ut << endl;
    f0ut.close();

    return 0;
}
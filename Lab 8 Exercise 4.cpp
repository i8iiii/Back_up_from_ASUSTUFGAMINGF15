#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

int countWord(char a[]) {
    int n = strlen(a);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isalpha(a[i]) && !isalpha(a[i + 1]))
            count++;
    }
    return count;
}

int main() {
    char input[100][1000];

    ifstream fin("input.txt"); 
    if (!fin.is_open()) {
        cerr << "Can't open this file!";
        return 1;
    }
    int i = 0;
    while (fin.getline(input[i], 1000))
        i++;
    fin.close();

    ofstream fout;
    fout.open("output.txt", ios::out | ios::trunc);
    if (!fout.is_open()) {
        cerr << "Can't open this file!";
        return 1;
    }
    int sum = 0;
    for (int j = 0; j < i; j++) 
        sum += countWord(input[j]);
    fout << sum;
    fout.close();
    return 0;
}
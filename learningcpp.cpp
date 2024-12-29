#include<iostream>
#include<cstring>

using namespace std;

int splitWords (char splitedString[][1000], char s[]) {
    int size = 0;
    char* token = strtok(s, " ");
    while (token) {
        strcpy(splitedString[size], token); 
        size++;
        token = strtok(NULL, " ");
    }
    return size;
}

void standardize(char a[]) {
    char b[100][1000];
    int m = splitWords(b, a);

    cout << b[0];
    for (int i = 1; i <= m; i++) {
        if (b[i][0] != '\0') {
            if (isalpha(b[i][0])) {
                cout << " " << b[i];
            } else {
                cout << b[i];
            }
        }
    }
}

int main() {
    char a[100];
    cin.getline(a, 100);
    standardize(a);
    return 0;
}
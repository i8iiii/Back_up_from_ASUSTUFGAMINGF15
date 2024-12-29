#include<iostream>
#include<cstring>

void sortWords(char a[], char b[][1000]) {
    int l = strlen(a);
    int m = 0, n = 0;

    for (int i = 0; i < l; i++) {
        if (isalpha(a[i])) {
            b[m][n] = a[i];
            n++;
        } else {
            m++;
            n = 0;
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (strcmp(b[i], b[j]) > 0) {
                char temp[100] = {};
                strcpy(temp, b[i]);
                strcpy(b[i], b[j]);
                strcpy(b[j], temp);
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        std::cout << b[i] << " ";
    }
}

int main() {
    char a[1000]; char b[100][1000];
    std::cin.getline(a, 1000);
    sortWords(a, b);
    return 0;
}
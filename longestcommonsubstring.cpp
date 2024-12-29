#include<iostream>
#include<cstring>
#include<cmath>

void FindLCS(char str1[],char str2[]) {
    int n = strlen(str1);
    int m = strlen(str2);
    int k = 0;
    int count = 0;
    int max = INT_MIN;
    int start;

    for (int i = 0; i < n; i++) {
        for (int j = k; j < m; j++) {
            if (str1[i] == str2[j] && isalpha(str1[i]) && isalpha(str2[j])) {
                k = j;
                i++;
                count++;
            } else {
                if (max < count) {
                    max = count;
                    start = i - max;
                }
                count = 0;
            }
        }
        k = 0;
    }

    if (strcmp(str1, str2) == 0) std::cout << str1;

    for (int i = start; i < start + max; i++) {
        std::cout << str1[i];
    }
}

int main() {
    char str1[] = "bruh";
    char str2[] = "bru";
    FindLCS(str1, str2);
    return 0;
}

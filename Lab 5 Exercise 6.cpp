#include<iostream>
#include<cstring>

int countWord(char a[]) {
    int n = strlen(a);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isalpha(a[i]) && !isalpha(a[i + 1]))
            count++;
    }
    return count;
}

void splitWords (char splitedString[][1000], char s[]) {
    int size = 0;
    char* token = strtok(s, " ");
    while (token) {
        strcpy(splitedString[size], token); 
        size++;
        token = strtok(NULL, " ");
    }
}

void reverse(char s[]) {
    int row = countWord(s);
    char split[100][1000];
    splitWords(split, s);
    for (int i = row - 1; i >=0 ; --i)
        std::cout << split[i] << " " ;
}

int main() {
    char old[1000];
    std::cin.getline(old, 1000);
    reverse(old);  
    return 0;
}
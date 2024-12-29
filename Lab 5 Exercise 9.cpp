#include<iostream>
#include<cstring>

int countWord(char a[]) {
    int l = strlen(a);
    int n = 0;
    for (int i = 0; i < l; i++) {
        if (isalpha(a[i]) && !isalpha(a[i + 1])) 
           n++;
    }
    return n;
}

int main() {
    char words[1000];
    std::cin.getline(words, 1000);
    std::cout << countWord(words);
    return 0;
}
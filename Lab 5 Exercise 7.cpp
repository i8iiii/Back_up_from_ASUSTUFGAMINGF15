#include<iostream>
#include<cstring>

void count(char a[], int &vowels, int &consonants) {
    int n = strlen(a);
    vowels = 0; consonants = 0;
    for (int i = 0; i < n; i++) {
        if (isalpha(a[i]) && (a[i] == 'u' || a[i] == 'e' || a[i] == 'o' || a[i] == 'a' || a[i] == 'i')) {
            vowels++;
        } else {
            if (isalpha(a[i])) {
                consonants++;
            }
        }
    }
}

int main() {
    int vowels, consonants;
    char word[1000];
    std::cin.getline(word, 1000);
    count(word, vowels, consonants);
    std::cout << "Vowels:  " << vowels << ", " << "Consonants:  " << consonants;
    return 0;
} 
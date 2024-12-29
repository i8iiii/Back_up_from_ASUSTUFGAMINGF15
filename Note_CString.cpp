#include <iostream> 
#include <cstring>
using namespace std;

void swap (char* &s, char* &t) {
    char temp[strlen(s)] = "";
    strcpy(temp, s);
    strcpy(s, t);
    strcpy(t, temp);
}
char toLowercase (char ch) {
    return ch > 'A' && ch < 'Z' ? ch + 32 : ch;
}
int freqency (char ch, char* s) {
    int count = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == ch) ++count;
    }
    return count;
}
int countWords (char* s) {
    int len = strlen(s);
    int i = 0;
    int count = 0;
    while (i < len) {
        while (i < len && s[i] == ' ')
            i++;
        if (s[i] != ' ' && i < len) count += 1;
        while (i < len && s[i] != ' ')
            i++;
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

int main() {
    cout << "RUNNING\n";
    char c[1000] = "hello toi bi mngu ";
    int n = countWords(c);
    char splited[n][1000];
    splitWords(splited, c);
    for (int i = 0; i < n; ++i) {
        cout << strlen(splited[i]) << ' ' << splited[i] << '\n';
    }
}
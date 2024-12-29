#include <iostream>
#include <cstring>

int main()
{
    char words[1000];
    std::cin.getline(words, 1000);
    char luumang[100][1000];
    int size(0);
    char *token = strtok(words, " ");
    while (token != NULL)
    {
        strcpy(luumang[size], token); 
        size++;
        token = strtok(NULL, " "); // di den lan tach tiep theo
    }

    int res = 0;
    int count[size] = {0};
    for (int i = 0; i < size - 1; i++) {
        if (count[i] == 0) {
            for (int j = i + 1; j < size; j++) {
                if (strcmp(luumang[i], luumang[j]) == 0) 
                    count[j] = 1;
            }
            res++;
        }
    }

    std::cout << res;
    return 0;
}
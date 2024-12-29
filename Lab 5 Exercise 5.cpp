#include <iostream>
#include <cstring>

using namespace std;

void UPtoLOW(char n[])
{
    int size = strlen(n);
    for (int i = 0; i < size; i++)
    { // chuyen tu UPPERCASE sang LOWERCASE
        if ('A' <= n[i] && n[i] <= 'Z')
        {
            n[i] += 32;
        }
    }
}

void sortLetter(char n[])
{
    int size = strlen(n);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        { // sap xep chuoi chu theo thu tu tang dan
            if (strcmp(n[i], s[j]) > 0)
                swap(n[i], n[j]);
        }
    }
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    int size = strlen(input);
    int dem[26] = {0};

    UPtoLOW(input);
    for (int i = 0; i < size; i++)
    {
        dem[input[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (dem[i] != 0)
        {   
            sortLetter(input);
            if ((char)(i + 97) != input[size - 1])
                cout << (char)(i + 97) << " : " << dem[i] << ", ";
            else
                cout << (char)(i + 97) << " : " << dem[i];
        }
    }

    return 0;
}

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int choice = 1;

    do
    {
        system("cls");

        cout << ((choice == 1) ? ">> " : "   ") << "1. Display student information" << endl;
        cout << ((choice == 2) ? ">> " : "   ") << "2. Add a new student" << endl;
        cout << ((choice == 3) ? ">> " : "   ") << "3. Remove a student" << endl;
        cout << ((choice == 4) ? ">> " : "   ") << "4. Update student information" << endl;
        cout << ((choice == 5) ? ">> " : "   ") << "5. Find the student with the highest GPA" << endl;
        cout << ((choice == 0) ? ">> " : "   ") << "0. Exit" << endl;

        char key;
        key = getch();

        switch (key)
        {
        // Up
        case 72:
            choice--;
            if (choice == -1)
                choice = 5;
            break;

        // Down
        case 80:
            choice = (choice + 1) % 6;
            break;

        // Enter
        case 13:
            switch (choice)
            {
            case 1:
                cout << "Function 1" << endl;
                break;
            case 2:
                cout << "Function 2" << endl;
                break;
            case 3:
                cout << "Function 3" << endl;
                break;
            case 4:
                cout << "Function 4" << endl;
                break;
            case 5:
                cout << "Function 5" << endl;
                break;
            case 0:
                return 0;
                break;
            default:
                break;
            }
            system("pause");
            break;

        default:
            break;
        }
    } while (true);

    return 0;
}

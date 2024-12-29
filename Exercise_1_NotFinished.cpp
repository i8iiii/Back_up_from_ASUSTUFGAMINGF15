#include <iostream>
#include <conio.h>

using namespace std;

struct Student
{
    string fullName;
    string studentID;
    string dob;
    double gpa;
};

int main()
{
    int n = 0;
    Student ID[100];
    Student s[100];
    int choice = 1;
    do
    {
        system("cls");

        cout << ((choice == 1) ? ">> " : "   ") << "1. Display student information" << endl;
        cout << ((choice == 2) ? ">> " : "   ") << "2. Add a new student" << endl;
        cout << ((choice == 3) ? ">> " : "   ") << "3. Remove a student (based on student ID)" << endl;
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
                if (n == 0)
                    cout << "No students!" << endl;
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        cout << "Student " << i + 1 << endl;
                        cout << "Name          : " << s[i].fullName << endl;
                        cout << "Student ID    : " << s[i].studentID << endl;
                        cout << "Date of birth : " << s[i].dob << endl;
                        cout << "GPA           : " << s[i].gpa << endl;
                        cout << "-------------------------------------" << endl;
                    }
                }
                break;
            case 2:
                n++;

                cout << "Enter name          : "; getline(cin, s[n - 1].fullName);
                cout << "Enter student ID    : "; getline(cin, s[n - 1].studentID);
                cout << "Enter date of birth : "; getline(cin, s[n - 1].dob);
                cout << "Enter GPA           : "; cin >> s[n - 1].gpa;
                cin.ignore();

                break;
            case 3:
                cout << "Student ID: ";
                getline(cin, ID->studentID);
                if (ID->studentID.size() < 8 || ID->studentID.size() > 8) {
                    cout << "Invalid Student ID!" << endl;
                } else {
                    for (int i = 0; i < n; i++) {
                        if (s[i].studentID == ID->studentID) {
                            n--;
                            s[i].fullName = s[i + 1].fullName;
                            s[i].studentID = s[i + 1].studentID;
                            s[i].dob = s[i + 1].dob;
                            s[i].gpa = s[i + 1].gpa;
                        }
                    }
                }
                break;
            case 4:
                cout << "";
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

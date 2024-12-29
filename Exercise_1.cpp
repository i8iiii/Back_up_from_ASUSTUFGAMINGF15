#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b; 
    b = temp;
}

struct Student {
    char firstName[100];
    char lastName[100];
    int mathScore;
    int literatureScore;
    int physicsScore;
};

int main () {
    
    Student* student;
    int number;
    
    ifstream fin("Test.txt");
    ofstream fout("res.txt");
    if (!fin.is_open() || !fout.is_open())
        cerr << "CANT NOT OPEN FILE" << endl;

    fin >> number;
    fin.ignore();
    student = new Student[number];
    for (int i = 0; i < number; i++) {
        fin.getline(student[i].firstName, 100, ' ');
        fin.getline(student[i].lastName, 100, ',');
        fin >> student[i].mathScore;
        fin.ignore();
        fin >> student[i].literatureScore;
        fin.ignore();
        fin >> student[i].physicsScore;
        fin.ignore();
    }
    
    for (int i = 0; i < number; i++) {
        cout << "First Name: " << student[i].firstName << endl; 
        cout << "Last Name: " << student[i].lastName << endl;
        cout << "Math Score: " << student[i].mathScore << endl;
        cout << "Literature Score: " << student[i].literatureScore << endl;
        cout << "Physics Score: " << student[i].physicsScore << endl;
        if (i != number - 1)
            cout << endl;
    }
    
    for (int i = 0; i < number; i++) {
        for (int j = i + 1; j < number; j++) {
            if (student[i].mathScore < student[j].mathScore) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        fout << student[i].firstName; 
        fout << student[i].lastName << ", ";
        fout << student[i].mathScore << ", ";
        fout << student[i].literatureScore << ", ";
        fout << student[i].physicsScore << endl;
    }

    delete[]student;
    fin.close();
    fout.close();
    return 0;
}
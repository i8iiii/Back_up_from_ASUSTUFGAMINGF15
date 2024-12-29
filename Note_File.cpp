#include <iostream> 
#include <cstring>
#include <fstream>
using namespace std;

struct student {
    int StudentID;
    char FullName[1000];
    float GPA;
    int YoB;
};

student Student[100];
int n = 0; 

void readFile(const char* fileName) {
    ifstream fin(fileName);
    if (!fin.is_open())
        cout << "ERROR" << endl;
    while (!fin.eof()) {
        fin >> Student[n].StudentID;
        fin.ignore();
        fin.getline(Student[n].FullName, 1000, '-');
        fin >> Student[n].GPA;
        fin.ignore();
        fin >> Student[n].YoB;
        fin.ignore();
        n++;
    }
    fin.close();
}

void findMaxGPA(const char* fileName) {
    ofstream fout(fileName);
    if (!fout.is_open())
        cout << "ERROR" << endl;
    float max = 0;
    for (int i = 0; i < n; i++) {
        if (max < Student[i].GPA)
            max = Student[i].GPA;
    }
    for (int i = 0; i < n; i++) {
        if (Student[i].GPA == max) {
            fout << Student[i].StudentID << '-';
            fout << Student[i].FullName << '-';
            fout << Student[i].GPA << '-';
            fout << Student[i].YoB;
            if (i != n - 1)
                fout << endl; 
        }
    }
    fout.close();
} 

void SameDepartment(const char* fileName) {
    ofstream fout(fileName);
    if (!fout.is_open())
        cout << "ERROR" << endl;

    int digits[n];
    for (int i = 0; i < n; i++) {
        digits[i] = (Student[i].StudentID / 1000);
    }

    int maxArr[n];
    int countMax = 0;
    int count = 1;
    int save;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (digits[i] == digits[j]) {
                count++;
            }
        }
        maxArr[i] = count;
        if (countMax < count) {
            countMax = count;
            save = i;
        }
        count = 1;
    }

    for (int i = 0; i < n; i++) {
        if (maxArr[i] == countMax) {
            if (digits[i] > digits[save]) {
                save = i;
            }
        }
    }

    fout << digits[save] << endl;
    for (int i = 0; i < n; i++) {
        if (Student[i].StudentID / 1000 == digits[save]) {
            fout << Student[i].FullName;
            if (i != n - 1)
                fout << endl; 
        }
    }
    fout.close();
}

int main() {
    readFile("INPUT.txt");
    // findMaxGPA("OUTPUT.txt");
    SameDepartment("OUTPUT.txt");
    return 0;
}

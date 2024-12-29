#include<iostream>
#include<cmath>
#include<cstring>

struct Student {
    char *name;
    double GPA;
};

struct ClassInfo {
    Student *studentInfo;
    int n;
};

void inputStudent(ClassInfo &info) {
    std::cout << "Nhap so hoc sinh: ";
    std::cin >> info.n;
    std::cin.ignore();
    info.studentInfo = new Student[info.n];
    for (int i = 0; i < info.n; i++) {
        info.studentInfo[i].name = new char[1000];
        std::cout << "Ho va ten: "; std::cin.getline(info.studentInfo[i].name, 1000);
        std::cout << "GPA: "; std::cin >> info.studentInfo[i].GPA;
        std::cin.ignore();
    }
}

void transfer(ClassInfo &des, const ClassInfo &src) {
    des.n = src.n;
    des.studentInfo = new Student[des.n];
    for (int i = 0; i < des.n; i++) {
        int len = strlen(src.studentInfo[i].name);
        des.studentInfo[i].name = new char[len + 1];
        for (int j = 0; j < len + 1; j++) {
            des.studentInfo[i].name[j] = src.studentInfo[i].name[j];
        }
        des.studentInfo[i].name[len + 1] = 0;
        des.studentInfo[i].GPA = src.studentInfo[i].GPA;
    }
}

void print(ClassInfo classes) {
    for (int i = 0; i < classes.n; i++) {
        std::cout << classes.studentInfo[i].name << " " <<  classes.studentInfo[i].GPA << std::endl;
    }
}

void releaseInfo(ClassInfo &des) {
    for (int i = 0; i < des.n; i++) {
        delete[]des.studentInfo[i].name;
    }
    delete[]des.studentInfo;
}

int main() {
    ClassInfo newClass;
    ClassInfo oldClass;
    inputStudent(oldClass);
    transfer(newClass, oldClass);
    print(newClass);
    releaseInfo(newClass);
    return 0;
}
//
// Created by ema on 23.3.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Student {
    char name[100];
    float gpa;
    int index;
    static int numStudents;
    static float totalGPA;
    static int nextIndex;
public:
    Student() {}
    Student(const char *name, float gpa) {
        strcpy(this->name, name);
        this->gpa = gpa;
        this->index = nextIndex;
        nextIndex++;
        numStudents++;
        totalGPA += gpa;
    }
    static int getNumStudents() { return numStudents; }
    static float averageGpa() {
        return totalGPA / numStudents;
    }
    void print() {
        cout << "Student name: " << name << endl;
        cout << "Student gpa: " << gpa << endl;
        cout<< "Student index: " << index << endl;
    }
};

int Student::nextIndex=230001;
int Student::numStudents = 0;
float Student::totalGPA = 0;

int main() {
    int n;
    cout << "Enter number of students" << endl;
    cin >> n;
    Student students[n];
    int id;
    char name[30];
    float gpa;
    for (int i = 0; i < n; i++) {
        cin >> name >> gpa;
        students[i] = Student(name, gpa);
    }

    for (int i = 0; i < n; i++) {
        students[i].print();
    }
    cout << "Total students: " << Student::getNumStudents() << endl;
    cout << "Total average: " << Student::averageGpa() << endl;
    return 0;
}
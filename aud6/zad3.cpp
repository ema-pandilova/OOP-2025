//
// Created by ema on 13.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Да се напише класа за опис ученици. За секој ученик се чува името (динамички алоцирана низа од знаци), просекот (децимален број) и школска година (цел број). За оваа класа да се имплементираат:
//
// Конструктори и
// деструктор
// Оператор
// ++
//  за зголемување на запишаната школска година за
// еден
// Оператор
// <<
//  за печатење на ученик со сите негови
// податоци
// Оператор
// >
//  за споредување на два ученика според
// просекот
// Потоа треба да се креира класа за опишување на паралелка што содржи динамички алоцирана низа од ученици,
//  како и број на елементи во низата
// .
//  За оваа класа да се имплементираат: Конструктори
// и деструктор
// Оператор
// +=
//  за додавање на нов студент во
// паралелката
// Оператор
// ++
//  за зголемување на запишаната школска година за еден за сите студенти во
// низата
// Оператор
// <<
//  за печатење на сите ученици во
// паралелката
// Метод nagrada што ги печати само оние ученици кои имаат просек
// 10.0.
// Метод najvisokProsek што го печати највисокиот просек во паралелката

class Student {
    char *name;
    int year;
    float gpa;
public:
    Student(char *name="",  float gpa=0.0, int year=0) {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->year = year;
        this->gpa = gpa;
    }
    Student(const Student &s) {
        this->name = new char[strlen(s.name)+1];
        strcpy(this->name, s.name);
        this->year = s.year;
        this->gpa = s.gpa;
    }
    ~Student() {
        delete [] this->name;
    }
    Student& operator=(const Student &s) {
        if(this!=&s) {
            delete [] this->name;
            this->name = new char[strlen(s.name)+1];
            strcpy(this->name, s.name);
            this->year = s.year;
            this->gpa = s.gpa;
        }
        return *this;
    }
    //prefix ++student cout<<++student 2
    Student & operator++() {
        this->year++;
        return *this;
    }
    //postfix student++ cout<<student++ 1
    Student operator++(int) {
        Student temp (*this); //kopija na momentalniot objekt
        this->year++;
        return temp;
    }
    friend ostream& operator<< (ostream& a, const Student& u)
    {
        return a << "Ime:" << u.name << ", godina:" << u.year << ",prosek:" << u.gpa << endl;
        // return a;
    }
    bool operator > (const Student &s) {
        return this->gpa > s.gpa;
    }
    friend class Paralelka;
};
class Paralelka {
    Student *students;
    int n;
public:
    Paralelka() {
        this->n=0;
        this->students = new Student[0];
    }

    Paralelka(const Paralelka &s) {
        this->n = s.n;
        this->students = new Student[this->n];
        for(int i=0;i<this->n;i++) {
            this->students[i] = s.students[i];
        }
    }
    ~Paralelka() {
        delete [] this->students;
    }
    Paralelka& operator=(const Paralelka &s) {
        if(this!=&s) {
            delete [] this->students;
            this->n = s.n;
            this->students = new Student[this->n];
            for(int i=0;i<this->n;i++) {
                this->students[i] = s.students[i];
            }
        }
        return *this;
    }
    Paralelka & operator+=(const Student &s) {
        Student *temp = new Student[this->n+1];
        for(int i=0;i<this->n;i++) {
            temp[i] = this->students[i];
        }
        temp[this->n]=s;
        this->n++;
        delete [] students;
        students = temp;
        return *this;

    }
    Paralelka operator++(int) {
        Paralelka temp (*this);
        for(int i=0;i<this->n;i++) {
            this->students[i]++;
        }
        return temp;

    }
    friend ostream& operator<< (ostream& o, const Paralelka& p)
    {
        for (int i = 0; i < p.n; i ++)
            o << p.students[i];
        return o;
    }

    void nagrada() {
        for(int i=0;i<this->n;i++) {
            if(students[i].gpa==10.0) {
                cout<<students[i]<<endl;
            }
        }
    }

    void najvisokProsek() {
        Student max = students[0];
        for(int i=0;i<this->n;i++) {
            if(students[i]>max) {
                max = students[i];
            }
        }
        cout<<max.gpa << endl;
    }


};
int main ()
{
    Student u1("Martina Martinovska", 9.5, 3);
    Student u2("Darko Darkoski", 7.3, 2);
    Student u3("Angela Angelovska", 10, 3);

    Paralelka p;
    p += u1;
    p += u2;
    p += u3;

    cout << p;
    cout << "Nagradeni:" << endl;
    p.nagrada();
    cout << endl;
    p.najvisokProsek();
    cout << endl;

    u2++;
    cout << p;
    cout << endl;
    p++;
    cout << p;
    cout<<p++;
    cout<<p;


    return 0;
}
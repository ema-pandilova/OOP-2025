//
// Created by ema on 27.2.25.
//
#include <iostream>
using namespace std;

// Simple example for structure

// struct Employee {
//     int id;
//     int salary;
//     char name[50];
//
//     void read() {
//         cin>>name>>id>>salary;
//     }
//
//     void print() {
//         cout<<name<<" "<<id<<" "<<salary;
//     }
//
// };
// // void read(Employee &e) {
// //     cin >> e.id >> e.salary>> e.name;
// // }
// // void print(Employee e) {
// //     cout << e.id << " " << e.salary << " " << e.name << endl;
// // }
// int main(){
//     Employee e;
//     // read(e);
//     // print(e);
//     e.read();
//     e.print();
//
// }

// References

// void swapWithoutReferences(int a, int b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }
// void swapWithReferences(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }
// void swapWithPointers(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main() {
//     int a,b;
//     cin >> a >> b; //5 6
//
//     swapWithoutReferences(a,b);
//
//     cout << a << " " << b << endl; // 5 6 (no change )
//
//     swapWithReferences(a,b);
//
//     cout << a << " " << b << endl; //6 5 (swap happens)
//
//     swapWithPointers(&a,&b);
//
//     cout << a << " " << b << endl; //6 5 (swap happens)
//
//     return 0;
// }

//Да се напише програма која ќе споредува два датуми (ден, месец, година) и ќе ја пресмета разликата во денови од едниот до другиот датум.
//Пресметките да се реализираат во посебни функции. За датумот да се дефинира посебна структура date.
struct Date {
    int day;
    int month;
    int year;

    int compareDates (Date other) {
        // 1 - ako prviot e pogolem od vtoriot, -1 ako vtoriot e pogolem od prviot i 0 ako se isti
        if (year > other.year) {
            return 1;
        }
        else if ( year < other.year) {
            return -1;
        }
        else {
            if (month > other.month) {
                return 1;
            }
            else if (month < other.month) {
                return -1;
            }
            else {
                if (day > other.day) {
                    return 1;
                }
                else if (day < other.day) {
                    return -1;
                }
                else {
                    return 0;
                }
            }
        }
    }

    int calculateDiff (Date other) {
        int diff = day - other.day;
        diff+= (month - other.month) * 30;
        diff+= (year - other.year) * 365;
        return diff; // vrakjame razlika vo denovi
    }


};
void read (Date &date) {
    cin>>date.day>>date.month>>date.year;
}
// int compareDates(Date d1, Date d2)
int main () {
    Date d1;
    Date d2;
    read(d1);
    read(d2);
    // compareDates(d1,d2);
    if (d1.compareDates (d2) == 1) {
        cout<<d1.calculateDiff(d2)<<endl;
    }
    else if (d1.compareDates (d2) == -1) {
        cout<<d2.calculateDiff(d1)<<endl;
    }
    else {
        cout<<"Datumite se isti"<<endl;
    }
}
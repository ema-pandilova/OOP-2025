//
// Created by ema on 23.3.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
#include <optional>
using namespace std;

// class Student {
//     char name[100];
//     int index;
//     int grade;
//     public:
//     Student() {}
//     Student(const char *name,int index, int grade ) {
//         strcpy(this->name,name);
//         this->index = index;
//         this->grade = 5;
//     }
//     Student(const Student &other) {
//         strcpy(this->name,other.name);
//         this->index = other.index;
//         this->grade = other.grade;
//     }
//
//     Student increaseGrade() {
//         this->grade = this->grade + 1;
//         return *this;
//     }
//
// };
// void whoIsBetter(Student &s1, Student &s2){
//
// }
// int main() {
//
//
// }

class Team {
    char name[100];
    int year;
    char city[100];
public:
    Team() {}
    Team (const char *name, int year, const char *city) {
        strcpy(this->name, name);
        this->year = year;
        strcpy(this->city, city);
    }
    Team(const Team &other) {
        cout << "Copy constructor" << endl;
        strcpy(this->name, other.name);
        this->year = other.year;
        strcpy(this->city, other.city);
    }
    void print() {
        cout << name << " " << year << " " << this->city << endl;
    }
    char *getName() {
        return name;
    }
};
class Match {
    Team host;
    Team guest;
    int hostGoals;
    int guestGoals;
    public:
    Match(){}
    Match(Team _host, Team guest, int hostGoals, int guestGoals) {
        host = _host;
        this->guest = guest;
        this->hostGoals = hostGoals;
        this->guestGoals = guestGoals;
    }
    Match(const Match &other) {
        this->host = other.host;
        this->guest = other.guest;
        this->hostGoals = other.hostGoals;
        this->guestGoals = other.guestGoals;
    }
    // friend bool isRematch(Match m1, Match m2);
    friend optional <Team> duel(Match m1, Match m2);
    bool isRematch( Match m2) {
        return (strcmp(host.getName(), m2.guest.getName())==0 && strcmp(this->guest.getName(), m2.host.getName())==0);
    }

};
// bool isRematch(Match m1, Match m2) {
//     return (strcmp(m1.host.getName(), m2.guest.getName())==0 && strcmp(m1.guest.getName(), m2.host.getName())==0);
// }

optional <Team> duel(Match m1, Match m2) {
    if (m1.isRematch(m2)){
        Team t1= m1.guest;
        Team t2=m1.host;
        int t1Goals = m1.guestGoals + m2.hostGoals;
        int t2Goals = m1.hostGoals + m2.guestGoals;
        if(t1Goals < t2Goals) {
            return t2;
        }
        else if(t2Goals < t1Goals) {
            return t1;
        }
        else {
            cout<<"Draw"<<endl;
            return std::nullopt;
        }
    }
    else {
        return std::nullopt;
    }
}



int main() {
    Team t1("Barcelona", 1889, "Barcelona");
    Team t2("Real Madrid", 1902, "Madrid");
    t1.print();
    Match m1(t1, t2, 3, 2);
    Match m2(t2, t1, 1, 1);
    cout<<m1.isRematch( m2);
    optional <Team> winner = duel(m1, m2);
    if(winner) {
        cout<<"Winner"<<endl;
    }
    else {
        cout<<"Draw"<<endl;
    }
}

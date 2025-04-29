//
// Created by ema on 19.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class User {
    char *username;
    char *company;
    int position;
    void copy(const User &u) {
        this->username = new char[strlen(u.username)+1];
        strcpy(this->username, u.username);
        this->company = new char[strlen(u.company)+1];
        strcpy(this->company, u.company);
        this->position = u.position;
    }
public:
    User(char *username="", char *company="", int position=0) {
        this->username = new char[strlen(username)+1];
        strcpy(this->username, username);
        this->company = new char[strlen(company)+1];
        strcpy(this->company, company);
        this->position = position;
    }
    User(const User &u) {
        copy(u);
    }
    User &operator=(const User &u) { //a=b
        if(this!= &u) {
            delete [] username;
            delete [] company;
            copy(u);
        }
        return *this;
    }
    ~User() {
        delete [] username;
        delete [] company;
    }
    friend istream &operator>>(istream &is, User &u) {
        char tempUsername[50];
        char tempCompany[50];

        is>>tempUsername>>tempCompany>>u.position;

        delete [] u.company;
        delete [] u.username;

        u.company = new char[strlen(tempCompany)+1];
        strcpy(u.company, tempCompany);

        u.username = new char[strlen(tempUsername)+1];
        strcpy(u.username, tempUsername);
        return is;
    }
    friend ostream &operator<<(ostream &os, const User &user) {
        return os << "Username: " << user.username
                  << " Company name: " << user.company
                  << " Position: " << user.position;
    }
    bool operator==(User &u) {
        return strcmp(this->username, u.username) == 0;
    }
    int getPosition()  {
        return this->position;
    }

};
class Group {
protected:
    User *users;
    int n;
    string name;
public:
    Group(string name="") {
        this->name=name;
        this->users=nullptr;
        this->n=0;
    }
    virtual void addMember (User & u) {
        for(int i=0;i<this->n;i++) {
            if(this->users[i]==u)
                return;
        }
        User *temp = new User[n+1];
        for(int i=0;i<this->n;i++) {
            temp[i]=this->users[i];
        }
        temp[n]=u;
        n++;
        delete [] users;
        users=temp;
    }
    double averagePositions() const{
        double sum=0;
        for(int i=0;i<this->n;i++) {
            sum+=users[i].getPosition();
        }
        return sum/n;
    }
    virtual double rating() const{
        return (10-this->averagePositions())*n/100;
    }
    friend ostream &operator<<(ostream &out, const Group &g) {
        out << "Group: " << g.name << endl;
        out << "Members: " << g.n << endl;
        out << "Rating: " << g.rating() << endl;
        out << "Members list: " << endl;
        if (g.n == 0) {
            out << "EMPTY" << endl;
        } else {
            for (int i = 0; i < g.n; i++) {
                out << i + 1 << ". " << g.users[i] << endl;
            }
        }

        return out;
    }
};
class PrivateGroup : public Group {
public:
    static int capacity;
    static float coeficient;
public:
    PrivateGroup(string name=""):Group(name) {

    }
    static void setCapacity(int capacity) {
        PrivateGroup::capacity = capacity;
    }
    void addMember (User & u) {
        if(n+1 > capacity) {
            return;
        }
        Group::addMember(u);
    }
    double rating() const {
        return (10 - averagePositions()) * (double(n) / capacity) * coeficient;
    }
    friend ostream &operator<<(ostream &os, const PrivateGroup &g) {
        Group group(g);
        os<<g;
        return os;

    }

};
int PrivateGroup::capacity=10;
float PrivateGroup::coeficient=0.8;
int main() {

    cout << "INTEGRATION TEST" << endl;
    char name[50];
    int nGroups;
    cin >> nGroups;
    Group **groups = new Group *[nGroups];
    for (int i = 0; i < nGroups; i++) {
        int type;
        cin >> type;
        cin >> name;
        if (type == 1) { //normal group
            groups[i] = new Group(name);
        } else { //private group
            groups[i] = new PrivateGroup(name);
        }
        int nUsers;
        cin >> nUsers;
        for (int j = 0; j < nUsers; j++) {
            User u;
            cin >> u;

            groups[i]->addMember(u);

        }
    }

    cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
    PrivateGroup::setCapacity(15);
    cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }

}
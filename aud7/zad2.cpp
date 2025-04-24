//
// Created by ema on 19.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class TennisPlayer {
protected:
    char *name;
    char *surname;
    bool playsInLeague;
    void copy(const TennisPlayer &tp) {
        this->name=new char[strlen(tp.name)+1];
        this->surname=new char[strlen(tp.surname)+1];
        strcpy(this->name, tp.name);
        strcpy(this->surname, tp.surname);
        this->playsInLeague = tp.playsInLeague;
    }
public:
    TennisPlayer(char *name="", char *surname="", bool playsInLeague=false) {
        this->name=new char[strlen(name)+1];
        this->surname=new char[strlen(surname)+1];
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->playsInLeague = playsInLeague;
    }

    TennisPlayer(const TennisPlayer &p) {
        copy(p);
    }
    ~TennisPlayer() {
        delete[] this->name;
        delete[] this->surname;
    }
    TennisPlayer &operator=(const TennisPlayer &p) {
        if(this!=&p) {
            delete[] this->name;
            delete[] this->surname;
            copy(p);
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const TennisPlayer &p) {
        os << p.name << " " << p.surname << " " << endl;
        if(p.playsInLeague) {
            cout<<"Playing"<<endl;
        }
        else {
            cout<<"Not Playing"<<endl;
        }
        return os;
    }

};
class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedTennisPlayer(char *name="noname", char *surname="noname", int rank=3):TennisPlayer(name, surname, true) {
        this->rank=rank;
    }
    RankedTennisPlayer(TennisPlayer tp, int rank=3) {
        TennisPlayer ::copy(tp);
        this->rank=rank;
    }
    RankedTennisPlayer(const RankedTennisPlayer &p) :TennisPlayer(p) {
        this->rank=p.rank;
    }
    RankedTennisPlayer &operator=(const RankedTennisPlayer &p) {
        if(this!=&p) {
            TennisPlayer::operator=(p);
            this->rank=p.rank;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &os, const RankedTennisPlayer &p) {
        TennisPlayer tp(p);
        os<<tp<<" "<<p.rank;
        return os;
    }
    // ~RankedTennisPlayer() {
    //     delete[] this->name;
    //     delete[] this->surname;
    // }

};
int main() {
    TennisPlayer tennisPlayer1("Rafael", "Nadal", true);
    cout << tennisPlayer1 << endl;
    RankedTennisPlayer tennisPlayer2(tennisPlayer1,2);
    cout << tennisPlayer2 << endl;
}
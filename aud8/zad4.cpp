//
// Created by ema on 28.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class HotelReservation {
protected:
    int days;
    int people;
    char contact[50];

public:
    HotelReservation(char *contact="", int days=0, int people=0) {
        this->days=days;
        this->people=people;
        strcpy(this->contact,contact);
    }

    virtual int price() {
        return people*days*25;
    }
    virtual int price(int amount) {
        return amount-price();
    }
};
class HalfBoardHotelReservation : public HotelReservation {
public:
    HalfBoardHotelReservation(char *contact="", int days=0, int people=0):HotelReservation(contact, days, people) {

    }

    int price() {
        return people*days*30;
    }
    int price(int amount) {
        return amount-(HotelReservation::price()+people*days*5);
    }
};

class Hotel {
    char name[20];
    int balance;
    public:
    Hotel(char *name="finki", int balance=0) {
        strcpy(this->name, name);
        this->balance=balance;
    }
    int pay(HotelReservation &hr, int amount) {
        int totalPrice = hr.price();
        balance+=totalPrice;
        return hr.price(amount);
    }
    friend ostream &operator<<(ostream &os, const Hotel &h) {
        os << h.name << " " << h.balance;
        return os;
    }
};

int main() {
    Hotel hotel("Finki", 1000);
    int n;
    cin >> n;
    HotelReservation ** reservations = new HotelReservation*[n];
    for (int i = 0; i < n; i++) {
        int type;// 1-HotelReservation, 2-HalfBoard...
        int days;
        int people;
        char contact[50];
        int deposit;
        cin>>type>>contact>>days>>people>>deposit;
        if(type==1) {
            reservations[i]=new HotelReservation(contact, days, people);
        }
        else if(type==2) {
            reservations[i]=new HalfBoardHotelReservation(contact, days, people);
        }
        cout<<"Contact: "<<contact<<endl;
        cout<<"Days: "<<days<<endl;
        cout<<"Price: "<<reservations[i]->price()<<endl;
        cout<<"hotel's change"<<hotel.pay(*reservations[i], deposit)<<endl;


    }
    cout<<endl;
    cout<<hotel;
}
// int main() {
//
//     Hotel h("Bristol");
//     HotelReservation *hr1 = new HotelReservation("Petko", 5, 5);
//     int cena = h.pay(*hr1, 1000);
//     if (cena != -1)
//         cout << "Kusur : " << cena << endl;
//     HalfBoardHotelReservation *hr2 =
//             new HalfBoardHotelReservation("Risto", 5, 5);
//     cena = h.pay(*hr2, 1000);
//     if (cena != -1)
//         cout << "Kusur : " << cena << endl;
//     //покажувач кон основна класа покажува кон објект од изведена
//     HotelReservation *hr3 = new HalfBoardHotelReservation("Ana",  4, 2);
//     cena = h.pay(*hr3, 100);
//     if (cena != -1)
//         cout << "Kusur : " << cena << endl;
//     HalfBoardHotelReservation hr4("Tome", 5, 3);
//     cena = h.pay(hr4, 1000);
//     if (cena != -1)
//         cout << "Kusur : " << cena << endl;
// }
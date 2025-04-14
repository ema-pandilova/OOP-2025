//
// Created by ema on 13.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Да се напише класа Array за работа со еднодимензионални полиња од целобројни елементи. За полето се чуваат информации за неговиот вкупен капцитет, тековниот број на елементи. Резервацијата на меморијата да се врши динамички.
//
// Во класата да се преоптоварат следните оператори:
// -
// +=
// за додавање нови броеви во полето и притоа ако е исполнет капацитетот на полето(низата) да се зголеми за
// 100
// %
// .
// -
// -=
// која ги брише сите појавувања на целоброниот аргумент во полето, а притоа капацитетот да не се промени
// .
// -
// <<
//  за печатење на елементите од полето
// .
// -
// [] за пристап до елемент и промена на вредноста на елемент од полето
// .
// -
// ==
//  за споредба на два објекти од класата Array
// .
//
// Да се тестира класата во main функција

class Array {
    int *array;
    int size;
    int capacity;
public:
    Array(int capacity = 5) {
        this->capacity = capacity;
        this->array = new int [capacity];
        this->size=0;
    }
    Array(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->array = new int [capacity];
        for (int i=0; i<size; i++) {
            this->array[i]=other.array[i];
        }
    }
    ~Array() {
        delete [] this->array;
    }

    Array& operator=(const Array &other) {
        if(this!=&other) {
            delete [] this->array;
            this->capacity = other.capacity;
            this->size = other.size;
            this->array = new int [capacity];
            for (int i=0; i<size; i++) {
                this->array[i]=other.array[i];
            }
        }
        return *this;
    }

    Array & operator+= (int number) {
        if(this->size == this->capacity) {
            int *temp = new int [this->capacity * 2];
            for(int i=0; i<this->size; i++) {
                temp[i]=this->array[i];
            }
            temp[this->size]=number;
            this->size++;
            this->capacity *= 2;
            delete [] this->array;
            this->array = temp;
        }
        else {
            this->array[this->size]=number;
            this->size++;
        }
        return *this;
    }

    Array & operator -= (int number) {
        int j=0;
        for(int i=0; i<this->size; i++) {
            if(this->array[i]!=number) {
                array[j++]=this->array[i];
            }
        }
        this->size = j;
        return *this;
    }

    friend ostream & operator<<(ostream & out, const Array &a ) {
        out<<"Array size: "<<a.size<<endl;
        out<<"Capacity: "<<a.capacity<<endl;
        for(int i=0; i<a.size; i++) {
            out<<a.array[i]<<endl;
        }
            return out;
    }
    int & operator[] (int index) {
        return array[index];
    }

    bool operator== (const Array &other) {
        if(this->size != other.size) {
            return false;
        }
        else {
            for(int i=0; i<this->size; i++) {
                if(this->array[i] != other.array[i]) {
                    return false;
                }
            }
        }
        return true;
    }

};
int main() {

    Array a;
    a += (6);
    a += (4);
    a += (3);
    a += (2);
    a += (1);


    Array b(a);
    b -= (2);
    b -= (3);

    a[0] = 9; //primena na operatorot [] 6=9

    cout << " a: " << a;
    cout << " b: " << b;

    if (a == b) cout << "Isti se";
    else cout << "Ne se isti";


    return 0;
}
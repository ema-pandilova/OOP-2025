//
// Created by ema on 19.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Square {
protected:
    int a;
public:
    Square(int a=1) {
        cout<<"S"<<endl;
        this->a = a;
    }
    Square(const Square& s) {
        cout<<"Square copy constructor called"<<endl;
        this->a = s.a;
    }
    ~Square() {
        cout<<"~S"<<endl;
    }
    int area() const{
        return a*a;
    }
    int perimeter() const{
        return 4*a;
    }
    friend ostream& operator<<(ostream& os, const Square& s) {
        os<<s.a<<" "<<s.area()<<" "<<s.perimeter();
        return os;
    }

};

class Rectangle : public Square {
    int b;
public:
    Rectangle(int a=1, int b=2):Square(a) {
        cout<<"R"<<endl;
        this->b=b;
    }
    Rectangle(const Rectangle& s) :Square(s) {
        cout<<"Rectangle copy constructor called"<<endl;
        this->b=s.b;
    }
    ~Rectangle() {
        cout<<"~R"<<endl;
    }
    friend ostream& operator<<(ostream& os, const Rectangle& s) {
        os<<s.a<<" "<<s.b<<" "<<s.perimeter()<<" "<<s.area();
        return os;
    }
    int area() const {
        return a*b;
    }
    int perimeter() const {
        return 2*a+2*b;
    }
};
int main() {
    // Square s;
    // cout<<s;
    Rectangle rect;
    cout<<rect;
}
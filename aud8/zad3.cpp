//
// Created by ema on 19.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//Voved vo polimorfizam


//1. virtual
//2. niza od pokazuvaci


class Animal {
protected:
    char name[20];
public:
    Animal(char *name="") {
        strcpy(this->name, name);
    }
    virtual void makeSound() {
        cout<<name<<"is making a sound rrrr"<<endl;
    }
};
class Dog: public Animal {
public:
    Dog(char *name="") :Animal(name) {
    }
    void makeSound() {
        cout<<name<<"is making a sound af af"<<endl;
    }
};

class Cow: public Animal {
public:
    Cow(char *name="") :Animal(name) {
    }
    void makeSound() {
        cout<<name<<" is making a sound mu mu"<<endl;
    }
};

int main() {
    // Animal *a = new Animal("A");
    // a->makeSound();
    // Animal *dog = new Dog("Lexi");
    // dog->makeSound();
    // Animal *cow = new Cow("Milka");
    // cow->makeSound();

    Animal ** animals=new Animal *[3];//deklaracija niza od pokazuvaci
    animals[0] = new Dog("Dog");
    animals[1] = new Cow("Milka");
    animals[2] = new Animal("test");
    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
    }
}
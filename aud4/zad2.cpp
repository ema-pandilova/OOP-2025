//
// Created by ema on 23.3.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Library;
class LibraryMember;
class Book {
    char name[100];
    char author[100];
    bool available;
public:
    Book() {}
    Book(const char *name, const char *author, bool available) {
        strcpy(this->name, name);
        strcpy(this->author, author);
        this->available = available;
    }
    Book(const Book &b) {
        strcpy(this->name, b.name);
        strcpy(this->author, b.author);
        this->available = b.available;
    }
    // void print() {
    //     cout << "Book name: " << name << endl;
    // }
    friend Library;
    friend void checkOutBook(LibraryMember lm, Library l, int index);
};
class Library {
    char name[100];
    int numBooks;
    Book books[100];
    public:
    Library() {
        strcpy(name,"Brakja Miladinovci");
        numBooks = 0;
    }
    void addBook (Book b) {
        if(numBooks<30) {
            books[numBooks]=b;
            numBooks++;
        }
        else {
            cout<<"The library is full"<<endl;
        }
    }
    void print() {
        cout<<"Library name: " << name << endl;
        for (int i=0; i<numBooks; i++) {
            cout<<"Book name: " << books[i].name << endl;
        }
    }
    friend void checkOutBook(LibraryMember lm, Library l, int index);
};
class LibraryMember{
    char name[100];
    int id;
    public:
    LibraryMember(const char *name, int id) {
        strcpy(this->name, name);
        this->id = id;
    }
    friend void checkOutBook(LibraryMember lm, Library l, int index);

};
void checkOutBook(LibraryMember lm, Library l, int index) {
    if(l.books[index].available) {
        cout << lm.name << " ID: " << lm.id << " checks out " << l.books[index].name << endl;
        l.books[index].available = false;
    }
    else {
        cout<<"The book is unavailable"<<endl;
    }
}
int main() {
    Library l1;
    int n;
    cout << "Enter the number of books" << endl;
    cin >> n;
    char name[30], author[30];
    bool availability;
    for (int i = 0; i < n; i++) {
        cin >> name >> author >> availability;
        Book b = Book(name, author, availability);
        l1.addBook(b);
    }
    l1.print();
    LibraryMember m1("Marko", 9541);
    int index;
    cin >> index;
    checkOutBook(m1, l1, index);
    return 0;
}

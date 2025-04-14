//
// Created by ema on 13.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//Example - Introduction to dynamic allocation
class Letter {
    //char content [100]; static allocation
    char * content;
    void copy(const Letter &other) {
        this->content = new char[strlen(other.content)+1];
        strcpy(this->content, other.content);
    }
public:
    Letter(char *content="") {
        this->content = new char[strlen(content)+1];
        strcpy(this->content, content);
    }
    // 1. copy constructor
    // 2. desctructor
    // 3. operator =
   Letter (const Letter &other) {
        // this->content = new char[strlen(other.content)+1];
        // strcpy(this->content, other.content);
        copy(other);
    }
    ~Letter() {
        delete [] this->content;
    }

   Letter & operator= (const Letter &other) {
        if(this!=&other) {
            delete [] this->content;
            // this->content = new char[strlen(other.content)+1];
            // strcpy(this->content, other.content);
            copy(other);
        }
        return *this;
    }
};

int main() {
    Letter letters[10];
}
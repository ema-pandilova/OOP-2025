#include <iostream>

using namespace std;

// Да се дефинира класа Letter во која се чува еден знак ch. За класата да се дефинираат:
// set метода
//
// lowerLetter метода со којашто ќе се претвори буквата во мала. Доколку не е буква да испечати порака за грешка  "Character is not a letter" (методи за користење: isalpha и tolower).
//
// print метода за печатење на вредноста на ch.
//
// Забранети се промени во main.
class Letter {
    char ch;
public:
    void set(char ch) {
        this->ch = ch;
    }
    void lowerLetter() {
        if(isalpha(ch)) {
            this->ch=tolower(this->ch);
        }
        else {
            cout<<"Character is not a letter"<<endl;
        }
    }
    void print() {
        cout<<this->ch<<endl;
    }
};
int main() {
    Letter obj;
    int n;
    cin >> n;
    int cmd;
    char k;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        switch (cmd) {
            case 1: {
                cin >> k;
                obj.set(k);
                obj.print();
                break;
            }
            case 2: {
                obj.lowerLetter();
                obj.print();
                break;
            }
            case 3: {
                cin >> k;
                Letter obj2;
                obj2.set(k);
                obj2.lowerLetter();
                obj2.print();
                break;
            }
            default: {
                obj.print();
                break;
            }
        }
    }
}

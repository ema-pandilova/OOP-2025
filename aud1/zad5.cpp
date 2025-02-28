//
// Created by ema on 27.2.25.
//
#include <iostream>
#include <unistd.h>
using namespace std;
#include <cstring>
#include <cctype>

struct City {
    char name[100];
    int population;
};

struct President {
    char name[100];
    char party[100];
};

struct Country {
    char name[100];
    President president;
    City capital;
    int population;
    void print() {
        cout << name << " "<< population << endl;
        cout << capital.name <<" "<<capital.population<< endl;
        cout << president.name << " " << president.party <<endl;
    }
};

void read (int n, Country *countries) {
    for (int i = 0; i < n; i++) {
        cin>>countries[i].name;
        cin>>countries[i].population;
        cin>>countries[i].capital.name>>countries[i].capital.population;
        cin>>countries[i].president.name>>countries[i].president.party;
    }

}

void printMaxPopulation(Country *countries,int n) {
    Country max = countries[0];
    for (int i = 1; i < n; i++) {
        if(countries[i].capital.population > max.capital.population) {
            max = countries[i];
        }
    }
    cout<<max.president.name;
}

int main() {
    int n;
    cin >> n;
    Country countries[n];
    read (n, countries);
    printMaxPopulation(countries,n);
}
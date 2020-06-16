
#pragma once

#include <string>
#include <vector>
#include "utils.h"
#include "MyException.h"

using namespace std;

class Artist {
    int id;
    string nume;
public:
    Artist(){}
    Artist(int i, string n):id(i),nume(n)){}
    Artist(const Artist &a){
        this->id = a.id;
        this->nume = a.nume;
    }
    Artist(string args, char sep){
        this->loadFromString(args, sep);
    }
    ~Artist(){}
    Artist& operator=(const Artist &a){
        this->id = a.id;
        this->nume = a.nume;
        return *this;
    }
    void loadFromString(string args, char sep){
        vector<string> elements = split(args, sep);
        if (elements.size() == 2){
            stringstream i(elements[0]);
            i >> this->id;
            this->nume = elements[1];
            stringstream n(elements[2]);
        }
        else{
            throw MyException("nu ati introdus un nr valid de argumente");
        }
    }
    string toStringDelimiter(char sep){
        return to_string(this->id) + sep + this->nume;
    }
    string getNume(){
        return this->nume;
    }
    int getID(){
        return this->id;
    }
    bool operator==(const Artist &a){
        return this->nume == a.nume;
    }
};

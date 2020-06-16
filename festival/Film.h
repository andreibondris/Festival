#pragma once

#include <string>
#include <vector>
#include "utils.h"
#include "MyException.h"

using namespace std;

class Film {
    int id;
    string nume;
    string data;
    string locatie;
    int locDisponibile;
    int locVandute;
public:
    Film(){}
    Film(int i, string n, string d, string l, int ld, int lv):id(i),nume(n),data(d),locatie(l),locDisponibile(ld),locVandute(lv)){}
    Film(const Film &f){
        this->id = f.id;
        this->nume = f.nume;
        this->locatie = f.locatie;
        this->data = f.data;
        this->locDisponibile = f.locDisponibile;
        this->locVandute = f.locVandute;
    }
    Film(string args, char sep){
        this->loadFromString(args, sep);
    }
    ~Film(){}
    Film& operator=(const F &f){
        this->id = f.id;
        this->nume = f.nume;
        this->locatie = f.locatie;
        this->data = f.data;
        this->locDisponibile = f.locDisponibile;
        this->locVandute = f.locVandute;
        return *this;
    }
    void loadFromString(string args, char sep){
        vector<string> elements = split(args, sep);
        if (elements.size() == 2){
            stringstream i(elements[0]);
            i >> this->id;
            this->nume = elements[1];
            stringstream n(elements[2]);
            this->data = elements[1];
            stringstream d(elements[2]);
            this->locatie = elements[1];
            stringstream l(elements[2]);
            ld >> this->locDisponibile;
            stringstream cu(elements[3]);
            lv >> this->locVandute;
        }
        else{
            throw MyException("nu ati introdus un nr valid de argumente");
        }
    }
    string toStringDelimiter(char sep){
        return to_string(this->id) + sep + this->nume + sep + this->data + sep + this->locatie + sep + to_string(this->locDisponibile) + sep + to_string(this->locVandute);
    }
    string getNume(){
        return this->nume;
    }
    int getID(){
        return this->id;
    }
    void setLocDisponibile(int ld){
        this->locDisponibile = ld;
    }
    int getLocDisponibile(){
        return this->locDisponibile;
    }
    void setLocVandute(int lv){
        this->locVandute = lv;
    }
    int getLocVandute(){
        return this->locVandute;
    }
    bool operator==(const Film &f){
        return this->nume == a.nume;
    }
};

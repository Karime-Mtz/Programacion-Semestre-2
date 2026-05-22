#ifndef INVITADO_H
#define INVITADO_H


# include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Invitado {

    private:
        string nombre;
        bool plus_one;

    public:
        Invitado();
        Invitado(string n, bool a);
        string get_nombre();
        bool get_plus_one();
        void set_nombre(string n);
        void set_plus_one(bool a);
};

Invitado::Invitado(){
    nombre = "";
    plus_one = false;
}

Invitado::Invitado(string n, bool a){
    nombre = n;
    plus_one = a;
}

string Invitado::get_nombre(){
    return nombre;
}

bool Invitado::get_plus_one(){
    return plus_one;
}

void Invitado::set_nombre(string n){
    nombre = n;
}

void Invitado::set_plus_one(bool a){
    plus_one = a;
}

#endif

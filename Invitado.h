/*
 * Proyecto Wedding Planner
 * Karime Martínez López
 * A01709690
 * 12/06/2026
 */

 /*
 * Clase Invitado contiene los métodos genéricos para el manejo de sus
 * atributos.
 *
 */


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

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Invitado
 */
Invitado::Invitado(){
    nombre = "";
    plus_one = false;
}

/**
 * Constructor recibe valores para llenar las variables de instancia
 *
 * @param string n: nombre, bool a: plus onne
 * @return objeto Invitado
 */
Invitado::Invitado(string n, bool a){
    nombre = n;
    plus_one = a;
}

/**
 * getter nombre
 *
 * @param
 * @return string: nombre del invitado
*/
string Invitado::get_nombre(){
    return nombre;
}

/**
 * getter plus one
 *
 * @param
 * @return bool: tienen plus one o no
*/
bool Invitado::get_plus_one(){
    return plus_one;
}

/**
 * setter nombre
 *
 * @param string n: nombre del invitado
 * @return 
*/
void Invitado::set_nombre(string n){
    nombre = n;
}

/**
 * setter plus one
 *
 * @param bool a: true en caso de tener plus one
 * @return 
*/
void Invitado::set_plus_one(bool a){
    plus_one = a;
}

#endif

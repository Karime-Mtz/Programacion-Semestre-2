/*
 * Proyecto Wedding Planner
 * Karime Martínez López
 * A01709690
 * 12/06/2026
 */

 /*
 * Clase Basico que hereda de clase Paquete. Contiene los métodos genéricos
 * para manejar sus atributos especiales. Sobreescribe la función 
 * calcular_precio().
 *
 */

#ifndef BASICO_H
#define BASICO_H

# include <string>
#include <iostream>
#include <sstream>
#include "Paquete.h"
using namespace std;

// Declaracion de clase Basico que hereda de clase Paquete
class Basico : public Paquete {
    
    // Declaracion de variables de instancia
    private:
        bool musica_dj;
        bool buffet;
        float precio_dj = 15000.0;
        float precio_buffet = 45000.0;

    // Declaracion de los metodos del objeto
    public:
        Basico();
        Basico(float p, bool d, bool dj, bool food);

        bool get_musica_dj();
        bool get_buffet();
        void set_musica_dj(bool dj);
        void set_buffet(bool food);

        // Sobreescritura
        float calcular_precio();
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Basico
 */
Basico::Basico() : Paquete() {
    musica_dj = false;
    buffet = false;
}

/**
 * Constructor recibe valores para llenar las variables de instancia
 * de este objeto, además de las variables heredadas
 *
 * @param float p: precio base del paquete, bool d: servicio de decoracion
 * incluido, bool dj: servicio de dj, bool food: servicio de comida.
 * @return objeto Basico
 */
Basico::Basico(float p, bool d, bool dj, bool food) : Paquete(p,d){
    musica_dj = dj;
    buffet = food;
}

/**
 * getter musica dj
 *
 * @param
 * @return bool: true si incluye el servicio musica dj
*/
bool Basico::get_musica_dj(){
    return musica_dj;
}

/**
 * getter buffet
 *
 * @param
 * @return bool: true si incluye buffet
*/
bool Basico::get_buffet(){
    return buffet;
}

/**
 * setter musica dj
 *
 * @param bool dj: servicio de musica dj
 * @return 
*/
void Basico::set_musica_dj(bool dj){
    musica_dj = dj;
}

/**
 * setter buffet
 *
 * @param bool food: servicio de buffet
 * @return 
*/
void Basico::set_buffet(bool food){
    buffet = food;
}

/**
 * Sobreescritura
 * calcula el precio del paquete dependiendo si incluye cada servicio
 *
 * @param
 * @return float con el calculo
*/
float Basico::calcular_precio() {
    float total = precio_base;
    
    if (decoracion)  total += precio_decoracion;
    if (musica_dj)   total += precio_dj;
    if (buffet)      total += precio_buffet;
    
    return total;
}

#endif

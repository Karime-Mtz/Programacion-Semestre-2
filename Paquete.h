/*
 * Proyecto Wedding Planner
 * Karime Martínez López
 * A01709690
 * 12/06/2026
 */

 /*
 * Clase Invitado contiene los métodos genéricos para el manejo de sus
 * atributos y calcula el precio del paquete de acuerdo a los servicios
 * incluidos. Tiene 2 clases hijas, cada una es un tipo diferente de 
 * paquete:
 * Basico y Premium
 *
 */

#ifndef PAQUETE_H
#define PAQUETE_H

# include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Declaracion de clase Paquete
class Paquete {

    // Declaracion de variables de instancia
    protected:
        float precio_base;
        bool decoracion;
        float precio_decoracion = 60000.0; 

    // Declaracion de los metodos del objeto    
    public:
        Paquete();
        Paquete(float p, bool d);
        bool get_decoracion();
        void set_decoracion(bool d);
        
        // Sobreescritura y declaración de la clase abstracta
        virtual float calcular_precio() = 0;
        
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Paquete
 */
Paquete::Paquete(){
    precio_base = 0.0;
    decoracion = false;
}

/**
 * Constructor recibe valores para llenar las variables de instancia
 *
 * @param float p: precio base del paquete, bool d: servicio de decoracion
 * incluido
 * @return objeto Paquete
 */
Paquete::Paquete(float p, bool d){
    precio_base = p;
    decoracion = d;
}

/**
 * getter decoracion
 *
 * @param
 * @return bool: true si la decoracion esta incluida
*/
bool Paquete::get_decoracion(){
    return decoracion;
}

/**
 * setter decoracion
 *
 * @param bool d: servicio de decoracion
 * @return 
*/
void Paquete::set_decoracion(bool d){
    decoracion = d;
}

#endif

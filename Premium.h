/*
 * Proyecto Wedding Planner
 * Karime Martínez López
 * A01709690
 * 12/06/2026
 */

 /*
 * Clase Premium que hereda de clase Paquete. Contiene los métodos genéricos
 * para manejar sus atributos especiales. Sobreescribe la función 
 * calcular_precio().
 *
 */

#ifndef PREMIUM_H
#define PREMIUM_H

# include <string>
#include <iostream>
#include <sstream>
#include "Paquete.h"
using namespace std;

// Declaracion de clase Premium que hereda de clase Paquete
class Premium : public Paquete {
    // Declaración de variables de instancia
    private:
        bool musica_vivo;
        bool tres_tiempos;
        bool fotografia;

        float precio_vivo = 35000.0;
        float precio_tres_t = 60000.0;
        float precio_foto = 20000.0;

    // Declaracion de los metodos del objeto
    public:
        Premium();
        Premium(float p, bool d, bool vivo, bool tres_t, bool fotos);
        bool get_musica_vivo();
        bool get_tres_tiempos();
        bool get_fotografia();
        void set_musica_vivo(bool vivo);
        void set_tres_tiempos(bool tres_t);
        void set_fotografia(bool fotos);

        // Sobreescritura
        float calcular_precio();
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Premium
 */
Premium::Premium() : Paquete() {
    musica_vivo = false;
    tres_tiempos = false;
    fotografia = false;
}

/**
 * Constructor recibe valores para llenar las variables de instancia
 * de este objeto, además de las variables heredadas
 *
 * @param float p: precio base del paquete, bool d: servicio de decoracion
 * incluido, bool vivo: musica en vivo, bool tres_t: comida de tres tiempos,
 * bool fotos: servicio de fotografías
 * @return objeto Premium
 */
Premium::Premium(float p, bool d, bool vivo, bool tres_t, bool fotos) : Paquete(p,d){
    musica_vivo = vivo;
    tres_tiempos = tres_t;
    fotografia = fotos;
}

/**
 * getter musica vivo
 *
 * @param
 * @return bool: servicio de musica en vivo
*/
bool Premium::get_musica_vivo(){
    return musica_vivo;
}

/**
 * getter tres tiempos
 *
 * @param
 * @return bool: servicio de comida de tres tiempos
*/
bool Premium::get_tres_tiempos(){
    return tres_tiempos;
}

/**
 * getter fotografia
 *
 * @param
 * @return bool: servicio de fotografia
*/
bool Premium::get_fotografia(){
    return fotografia;
}

/**
 * setter musica vivo
 *
 * @param bool: musica en vivo
 * @return 
*/
void Premium::set_musica_vivo(bool vivo){
    musica_vivo = vivo;
}

/**
 * setter tres tiempos
 *
 * @param bool: comida de tres tiempos
 * @return 
*/
void Premium::set_tres_tiempos(bool tres_t){
    tres_tiempos = tres_t;
}

/**
 * setter fotografia
 *
 * @param bool: fotografia
 * @return 
*/
void Premium::set_fotografia(bool fotos){
    fotografia = fotos;
}

/**
 * Sobreescritura
 * calcula el precio del paquete dependiendo si incluye cada servicio
 *
 * @param
 * @return float con el calculo
*/
float Premium::calcular_precio() {
    float total = precio_base;
    
    if (decoracion == true) {
        total += precio_decoracion;
    }
    if (musica_vivo == true) {
        total += precio_vivo;
    }
    if (tres_tiempos == true) {
        total += precio_tres_t;
    }
    if (fotografia == true) {
        total += precio_foto;
    }
    return total;
}

#endif

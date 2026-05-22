#ifndef PREMIUM_H
#define PREMIUM_H

# include <string>
#include <iostream>
#include <sstream>
#include "Paquete.h"
using namespace std;

class Premium : public Paquete {
    private:
        bool musica_vivo;
        bool tres_tiempos;
        bool fotografia;

        float precio_vivo = 35000.0;
        float precio_tres_t = 60000.0;
        float precio_foto = 20000.0;

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

Premium::Premium() : Paquete() {
    musica_vivo = false;
    tres_tiempos = false;
    fotografia = false;
}

Premium::Premium(float p, bool d, bool vivo, bool tres_t, bool fotos) : Paquete(p,d){
    musica_vivo = vivo;
    tres_tiempos = tres_t;
    fotografia = fotos;
}

bool Premium::get_musica_vivo(){
    return musica_vivo;
}

bool Premium::get_tres_tiempos(){
    return tres_tiempos;
}

bool Premium::get_fotografia(){
    return fotografia;
}

void Premium::set_musica_vivo(bool vivo){
    musica_vivo = vivo;
}

void Premium::set_tres_tiempos(bool tres_t){
    tres_tiempos = tres_t;
}

void Premium::set_fotografia(bool fotos){
    fotografia = fotos;
}

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

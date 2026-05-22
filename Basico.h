#ifndef BASICO_H
#define BASICO_H

# include <string>
#include <iostream>
#include <sstream>
#include "Paquete.h"
using namespace std;

class Basico : public Paquete {
    
    private:
        bool musica_dj;
        bool buffet;
        float precio_dj = 15000.0;
        float precio_buffet = 45000.0;

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

Basico::Basico() : Paquete() {
    musica_dj = false;
    buffet = false;
}

Basico::Basico(float p, bool d, bool dj, bool food) : Paquete(p,d){
    musica_dj = dj;
    buffet = food;
}

bool Basico::get_musica_dj(){
    return musica_dj;
}

bool Basico::get_buffet(){
    return buffet;
}

void Basico::set_musica_dj(bool dj){
    musica_dj = dj;
}

void Basico::set_buffet(bool food){
    buffet = food;
}

float Basico::calcular_precio() {
    float total = precio_base;
    
    if (decoracion)  total += precio_decoracion;
    if (musica_dj)   total += precio_dj;
    if (buffet)      total += precio_buffet;
    
    return total;
}

#endif

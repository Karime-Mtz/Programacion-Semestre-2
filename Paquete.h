#ifndef PAQUETE_H
#define PAQUETE_H

# include <string>
#include <iostream>
#include <sstream>
using namespace std;

// clase abstracta
class Paquete {

    protected:
        float precio_base;
        bool decoracion;
        float precio_decoracion = 60000.0; 

    public:
        Paquete();
        Paquete(float p, bool d);
        bool get_decoracion();
        void set_decoracion(bool d);
        
        // sobreescritura
        virtual float calcular_precio() = 0;
        
};

Paquete::Paquete(){
    precio_base = 0.0;
    decoracion = false;
}

Paquete::Paquete(float p, bool d){
    precio_base = p;
    decoracion = d;
}

bool Paquete::get_decoracion(){
    return decoracion;
}

void Paquete::set_decoracion(bool d){
    decoracion = d;
}

#endif

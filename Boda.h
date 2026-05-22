#ifndef BODA_H
#define BODA_H

# include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Boda {

    private:
        string novia;
        string novio;
        string lugar;
        string fecha;
        float presupuesto;
        
        Invitado lista_invitados[100];
        int num_invitados;
        int total_personas;
       
        Basico paquete_basico;
        Premium paquete_premium;
        int tipo_paquete; 
        // 1 = Basico, 2 = Premium, 0 = No tiene paquete

    public:
        Boda();
        // Constructor para cada tipo de paquete
        Boda(string bride, string groom, string place, string date, float cost, Basico paq);
        Boda(string bride, string groom, string place, string date, float cost, Premium paq);

        string get_novia();
        string get_novio();
        string get_lugar();
        string get_fecha();
        float get_presupuesto();
        int get_num_invitados();
        int get_total_personas();

        Basico get_paquete_basico();
        Premium get_paquete_premium();
        int get_tipo_paquete();

        void set_novia(string bride);
        void set_novio(string groom);
        void set_lugar(string place);
        void set_fecha(string date);
        void set_presupuesto(float cost);

        void set_paquete_basico(Basico paq);
        void set_paquete_premium(Premium paq);

        string mostrar_invitados();
        void agregar_invitado(string name, bool acomp);
        float calcular_costo_boda();
};

Boda::Boda(){
    novia = "";
    novio = "";
    lugar = "";
    fecha = "";
    presupuesto = 0.0;
    num_invitados = 0;
    total_personas = 0;
    tipo_paquete = 0;
}

Boda::Boda(string bride, string groom, string place, string date, float cost, Basico paq) {
    novia = bride;
    novio = groom;    lugar = place;
    fecha = date;
    presupuesto = cost;
    num_invitados = 0;
    total_personas = 0;
    paquete_basico = paq;
    tipo_paquete = 1;
}

Boda::Boda(string bride, string groom, string place, string date, float cost, Premium paq) {
    novia = bride;
    novio = groom;
    lugar = place;
    fecha = date;
    presupuesto = cost;
    num_invitados = 0;
    total_personas = 0;
    paquete_premium = paq;
    tipo_paquete = 2;
}

string Boda::get_novia(){
    return novia;
}

string Boda::get_novio(){
    return novio;
}

string Boda::get_lugar(){
    return lugar;
}

string Boda::get_fecha(){
    return fecha;
}

float Boda::get_presupuesto(){
    return presupuesto;
}

int Boda::get_num_invitados(){
    return num_invitados;
}

int Boda::get_total_personas(){
    return total_personas;
}

Basico Boda::get_paquete_basico() { 
    return paquete_basico; 
}

Premium Boda::get_paquete_premium() { 
    return paquete_premium; 
}

int Boda::get_tipo_paquete() { 
    return tipo_paquete; 
}

void Boda::set_novia(string bride){
    novia = bride;
}

void Boda::set_novio(string groom){
    novio = groom;
}

void Boda::set_lugar(string place){
    lugar = place;
}

void Boda::set_fecha(string date){
    fecha = date;
}

void Boda::set_presupuesto(float cost){
    presupuesto = cost;
}

void Boda::set_paquete_basico(Basico paq) {
    paquete_basico = paq;
    tipo_paquete = 1;
}

void Boda::set_paquete_premium(Premium paq) {
    paquete_premium = paq;
    tipo_paquete = 2;
}

string Boda::mostrar_invitados(){
    stringstream invitados;
    for (int i = 0; i < num_invitados; i++) {
        invitados << "Invitado " << i+1 << ": " << lista_invitados[i].get_nombre();
        if (lista_invitados[i].get_plus_one()) {
            invitados << " + 1";
        }
        invitados << endl;
    }
    return invitados.str();
}

void Boda::agregar_invitado(string name, bool acomp){
    if (num_invitados >= 500) {
        cout << "Límite de invitados alcanzado para esta boda." << endl;
    } else {
        lista_invitados[num_invitados] = Invitado(name, acomp);
        num_invitados++;
        
        if (acomp == true) {
            total_personas += 2;
        } else {
            total_personas += 1;
        }
    }
}

float Boda::calcular_costo_boda() {
    if (tipo_paquete == 1) {
        return paquete_basico.calcular_precio();
    } else if (tipo_paquete == 2) {
        return paquete_premium.calcular_precio();
    } else {
    return 0.0; 
    }
}

#endif

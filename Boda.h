/*
 * Proyecto Wedding Planner
 * Karime Martínez López
 * A01709690
 * 12/06/2026
 */

 /*
 * Clase Boda contiene los métodos genéricos para el manejo de sus
 * atributos, crea los invitados y los registra en una lista, y calcula
 * su costo.
 *
 */

#ifndef BODA_H
#define BODA_H

# include <string>
#include <iostream>
#include <sstream>

using namespace std;

// Declaracion de clase Boda
class Boda {

    private:
        // Declaracion de variables de instancia
        string nombre;
        string novia;
        string novio;
        string lugar;
        string fecha;
        float presupuesto;
        
        Invitado lista_invitados[100];
        int num_invitados;
        int total_personas;
       
        Paquete* paquete;
        int tipo_paquete; 
        // 1 = Basico, 2 = Premium, 0 = No tiene paquete

    public:
        // Declaracion de los métodos del objeto

        //Sobrecarga de constructores
        Boda();
        Boda(string bride, string groom, string place, string date, float cost, Paquete* pq);

        string get_nombre();
        string get_novia();
        string get_novio();
        string get_lugar();
        string get_fecha();
        float get_presupuesto();
        int get_num_invitados();
        int get_total_personas();

        Paquete* get_paquete();
        int get_tipo_paquete();

        void set_novia(string bride);
        void set_novio(string groom);
        void set_lugar(string place);
        void set_fecha(string date);
        void set_presupuesto(float cost);

        // Sobrecarga
        void set_paquete(Basico &paq);
        void set_paquete(Premium &paq);

        string mostrar_detalles();
        string mostrar_invitados();
        void agregar_invitado(string name, bool acomp);
        float calcular_costo_boda();
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Boda
 */
Boda::Boda(){
    nombre = "";
    novia = "";
    novio = "";
    lugar = "";
    fecha = "";
    presupuesto = 0.0;
    num_invitados = 0;
    total_personas = 0;
    tipo_paquete = 0;
}

/**
 * Constructor que recibe valores para llenar las variables de instancia
 *
 * @param string bride: nombre de la novia, string groom: nombre del novio, 
 * string place: lugar, string date: fecha, float cost: costo, Paquete* pq: 
 * apuntador tipo paquete
 * @return objeto Boda
 */
Boda::Boda(string bride, string groom, string place, string date, float cost, Paquete* pq) {
    nombre = bride + "_" + groom;
    novia = bride;
    novio = groom;    lugar = place;
    fecha = date;
    presupuesto = cost;
    num_invitados = 0;
    total_personas = 0;
    paquete = pq;
    tipo_paquete = 1;
}

/**
 * getter nombre
 * le asigna un nombre a la boda de acuerdo al nombre de los novios
 * @param
 * @return string: nombre de la boda
*/
string Boda::get_nombre() {
    string n_novia = novia;
    string n_novio = novio;

    for (char &c : n_novia) c = tolower(c);
    for (char &c : n_novio) c = tolower(c);
    
    return n_novia + "_" + n_novio;
}

/**
 * getter novia
 *
 * @param
 * @return string: nombre de la novia
*/
string Boda::get_novia(){
    return novia;
}

/**
 * getter novio
 *
 * @param
 * @return string: nombre del novio
*/
string Boda::get_novio(){
    return novio;
}

/**
 * getter lugar
 *
 * @param
 * @return string: lugar de la boda
*/
string Boda::get_lugar(){
    return lugar;
}

/**
 * getter fecha
 *
 * @param
 * @return string: fecha de la boda
*/
string Boda::get_fecha(){
    return fecha;
}

/**
 * getter presupuesto
 *
 * @param
 * @return float: presupuesto de la boda
*/
float Boda::get_presupuesto(){
    return presupuesto;
}

/**
 * getter numero de invitados
 *
 * @param
 * @return int: cantidad de invitados de la boda
*/
int Boda::get_num_invitados(){
    return num_invitados;
}

/**
 * getter total de personas
 *
 * @param
 * @return int: cantidad de invitados más acompañantes
*/
int Boda::get_total_personas(){
    return total_personas;
}

/**
 * getter paquete
 *
 * @param
 * @return Paquete: paquete asignado a la boda
*/
Paquete* Boda::get_paquete() { 
    return paquete; 
}

/**
 * getter tipo paquete
 *
 * @param
 * @return int: número que indica el tipo de paquete
*/
int Boda::get_tipo_paquete() { 
    return tipo_paquete; 
}

/**
 * setter novia
 *
 * @param string: nombre de la novia
 * @return 
*/
void Boda::set_novia(string bride){
    novia = bride;
    nombre = novia + "_" + novio;
}

/**
 * setter novio
 *
 * @param string: nombre del novio
 * @return 
*/
void Boda::set_novio(string groom){
    novio = groom;
    nombre = novia + "_" + novio;
}

/**
 * setter place
 *
 * @param string:lugar
 * @return 
*/
void Boda::set_lugar(string place){
    lugar = place;
}

/**
 * setter date
 *
 * @param string: fecha
 * @return 
*/
void Boda::set_fecha(string date){
    fecha = date;
}

/**
 * setter presupuesto
 *
 * @param float: presupuesto de la boda
 * @return 
*/
void Boda::set_presupuesto(float cost){
    presupuesto = cost;
}

/**
 * setter paquete basico
 *
 * @param Paquete: paquete de la boda basico
 * @return 
*/
void Boda::set_paquete(Basico &paq) {
    paquete = &paq;
    tipo_paquete = 1;
}

/**
 * setter paquete premium
 *
 * @param string: paquete de la boda premium
 * @return 
*/
void Boda::set_paquete(Premium &paq) {
    paquete = &paq;
    tipo_paquete = 2;
}

/**
 * Muestra los atributos de un objeto tipo Boda a través de stringstream
 *
 * @param
 * @return string con los detalles
*/
string Boda::mostrar_detalles(){
    stringstream detalles;
    detalles << "\nNovia: " << novia << endl;
    detalles << "Novio: " << novio << endl;
    detalles << "Fecha: " << fecha << endl;
    detalles << "Lugar: " << lugar << endl;
    detalles << "Presupuesto: " << presupuesto << endl;

    if (tipo_paquete == 1){
        detalles << "Paquete: Basico" << endl;
    } else {
        detalles << "Paquete: Premium" << endl;
    }
    return detalles.str();
}

/**
 * Muestra el nombre de todos los invitados, si tienen un acompañante y
 * la cantidad de personas que asisitirán a la boda
 *
 * @param
 * @return string con los nombres de los invitados
*/
string Boda::mostrar_invitados(){
    stringstream invitados;
    if (num_invitados == 0){
        invitados << "\nTodavia no hay invitados registrados" << endl;
    } else{
        for (int i = 0; i < num_invitados; i++) {
            invitados << "Invitado " << i+1 << ": " << lista_invitados[i].get_nombre();
            if (lista_invitados[i].get_plus_one()) {
                invitados << " + 1";
            }
            invitados << endl;
        }
        invitados << "\nNumero de invitados registrados: " << get_num_invitados() << endl;
        invitados << "Numero total de personas: " << get_total_personas() << endl;
    }
    return invitados.str();
}

/**
 * Permite registrar nuevos invitados a la lista si no se ha alcanzado 
 * el limite y actualiza la cantidad de personas en la boda.
 *
 * @param string name: nombre del invitado, bool acomp: si tienen plus one
 * @return 
*/
void Boda::agregar_invitado(string name, bool acomp){
    if (num_invitados >= 100) {
        cout << "\nLímite de invitados alcanzado para esta boda." << endl;
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

/**
 * Uso de polimorfismo
 * Calcula el costo de la boda, dependiendo de su paquete
 *
 * @param
 * @return 
*/
float Boda::calcular_costo_boda() {
    if (tipo_paquete == 1) {
        return paquete -> calcular_precio();
    } else if (tipo_paquete == 2) {
        return paquete -> calcular_precio();
    } else {
    return 0.0; 
    }
}

#endif

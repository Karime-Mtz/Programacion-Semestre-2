#include <iostream>
#include <string>
#include <sstream>
#include <tuple>

using namespace std;

#include "Invitado.h"
#include "Paquete.h"
#include "Basico.h"
#include "Premium.h"
#include "Boda.h"
#include "Empresa.h"

char menu(){

    // Imprime las opciones que se pueden realizar en el programa
    cout << "\nElige una de las siguientes opciones "
        "(a/b/c/d):" 
     << endl;
    cout << "a) Mostrar todas las bodas" << endl;
    cout << "b) Registrar nueva boda" << endl;
    cout << "c) Consultar informacion de una boda" << endl;
    cout << "d) Salir\n" << endl;

    char opcion;
    // Lee la opcion que ha sido seleccionada
    cin >> opcion;
    cin.ignore();    
    return opcion;
}

char menu2() {
    // Imprime las opciones que se pueden realizar en el programa
    cout << "\n¿Que te gustaria realizar? "
        "(a/b/c/d):" 
     << endl;
    cout << "a) Mostrar lista de invitados" << endl;
    cout << "b) Agregar invitado" << endl;
    cout << "c) Cotizar boda" << endl;
    cout << "d) Regresar\n" << endl;

    char opcion;
    // Lee la opcion que ha sido seleccionada
    cin >> opcion;
    cin.ignore();    
    return opcion;
}

string a_minusculas(string s) {
    // c es una referencia del caracter actual de s
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

int posicion_boda(Empresa &empresa, string novia, string novio) {
    string nombre_buscado;
    novio = a_minusculas(novio);
    novia = a_minusculas(novia);
    nombre_buscado = novia + "_" + novio; 

    for (int i = 0; i < empresa.get_num_bodas(); i++) {

        if (empresa.get_boda(i).get_nombre() == nombre_buscado) {
            return i;
        }
    }
    return -1;
}

int elegir_paquete() {
    int tipo;
    cout << "¿Que paquete te gustaria? (1/2)\n"
    "1.- Basico\n2.- Premium\n";

    while (!(cin >> tipo) || tipo < 1 || tipo > 2) {
        cout << "Respuesta no valida. Elige un numero del 1 al 2\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "¿Que paquete te gustaria? (1/2)\n"
    "1.- Basico\n2.- Premium\n";
    }
    cin.ignore();

    return tipo;
}

bool elegir_servicio(string servicio) {
    int opcion;
    cout << "¿Te gustaría agregar el servicio de " << servicio << "? (1/2)\n"
    "1.- Si\n2.- No\n";

    while (!(cin >> opcion) || opcion < 1 || opcion > 2) {
        cout << "Respuesta no valida. Elige un numero del 1 al 2\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "¿Te gustaría agregar música de DJ? (1/2)\n"
    "1.- Si\n2.- No\n";
    }
    cin.ignore();

    if (opcion == 1){
        return true;
    } else {
        return false;
    }
}

Basico crear_paquete_basico(){
    float precio_base = 80000.0;
    bool decoracion = elegir_servicio("decoracion");
    bool dj = elegir_servicio("musica de DJ");
    bool buffet = elegir_servicio("buffet");

    Basico paquete_basico(precio_base, decoracion, dj, buffet);
    return paquete_basico;
}

Premium crear_paquete_premium(){
    float precio_base = 80000.0;
    bool decoracion = elegir_servicio("decoracion");
    bool vivo = elegir_servicio("musica en vivo");
    bool tres_t = elegir_servicio("comida de tres tiempos");
    bool fotos = elegir_servicio("fotografías");

    Premium paquete_premium(precio_base, decoracion, vivo, tres_t, fotos);
    return paquete_premium;
}

Boda crear_boda(int tipo) {
    string novia, novio, fecha, lugar;
    float presupuesto;
    Boda boda_creada;
    Basico paqueteB;
    Premium paqueteP;

    cout << "Nombre de la novia: " << endl;
    getline(cin, novia);
    cout << "Nombre del novio: " << endl;
    getline(cin, novio);
    cout << "Lugar: " << endl;
    getline(cin, lugar);
    cout << "Fecha: " << endl;
    getline(cin, fecha);
    cout << "Presupuesto: " << endl;
    cin >> presupuesto;

    if (tipo == 1){
        paqueteB = crear_paquete_basico();
        boda_creada = Boda(novia, novio, lugar, fecha, presupuesto, paqueteB);
    } else {
        paqueteP = crear_paquete_premium();
        boda_creada = Boda(novia, novio, lugar, fecha, presupuesto, paqueteP);
    }
    return boda_creada;
}

int buscar_boda(Empresa &empresa){
    string novia, novio;
    cout << "¿Cual es el nombre de la novia?" << endl;
    getline(cin, novia);
    cout << "¿Cual es el nombre del novio?" << endl;
    getline(cin, novio);

    int position = posicion_boda(empresa, novia, novio);
    return position;
}

void consultar_info(Empresa &empresa, int position){

    if (position == -1) {
        cout << "No se encontro la boda" << endl;
    } else {
        // Imprime los datos usando el método del objeto libro
        cout << empresa.get_boda(position).mostrar_detalles();
    }
}

void mostrar_invitados(Empresa &empresa, int position){
    if (position == -1) {
        cout << "No se encontro la boda" << endl;
    } else {
        cout << empresa.get_boda(position).mostrar_invitados() << endl;
    }
}

void agregar_invitado(Empresa &empresa, int position){
     if (position == -1) {
        cout << "No se encontro la boda" << endl;
        return;
    }
    
    string invitado;
    int acomp;

    cout << "\nNombre del invitado: ";
    getline(cin, invitado);

    cout << "¿Tiene acompañante? (1/2)" << endl;
    cout << "1.- Si" << endl;
    cout << "2.- No" << endl;

    while (!(cin >> acomp) || acomp < 1 || acomp > 2) {
        cout << "Respuesta no valida. Elige un numero del 1 al 2\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "¿Tiene plus one? (1/2)\n1.- Si\n2.- No\n";
    }
    cin.ignore();

    bool tiene_acomp;

    if(acomp == 1){
        tiene_acomp = true;
    } else {
        tiene_acomp = false;
    }

    empresa.get_boda(position).agregar_invitado(invitado, tiene_acomp);
    cout << "Invitado agregado" << endl;
    
}

void cotizar(Empresa &empresa, int position){
    if (position == -1) {
        cout << "No se encontro la boda" << endl;
    } else {
        Boda boda_actual = empresa.get_boda(position);
        cout << "Costo de la boda: " << boda_actual.calcular_costo_boda() << endl;
        cout << "Presupuesto inicial: " << boda_actual.get_presupuesto() << endl;
    }
}


int main() {

// Creación de empresa
Empresa QroWeddings("Qro Weddings");

// Creación de paquetes
Basico PaqueteBodaLago(30000, true, true, true);
Basico PaqueteSalon(30000, true, false, true);
Premium PaqueteBodaViñedo(30000, true, true, false, true);

// Creación de Bodas
Boda Isabela_Esteban("Isabela","Esteban", "Lago de las Canadas", "15/07/2023", 180000.0, PaqueteBodaLago);
Boda Erica_Juan("Erica", "Juan Pablo", "Salon Tulipanes", "01/02/2021", 165000.0, PaqueteSalon);
Boda Aurora_Mauricio("Aurora", "Mauricio", "Vinedo del norte", "25/11/2023", 230000.0, PaqueteBodaViñedo);

QroWeddings.agregar_boda(Isabela_Esteban);
QroWeddings.agregar_boda(Erica_Juan);
QroWeddings.agregar_boda(Aurora_Mauricio);

while (true) {
        // Muestra el menu principial y recibe la opcion elegida
        char choice = menu();

        // Ejecuta las funciones de acuerdo a la opcion elegida
        switch (choice) {
            case 'a': {
                cout << QroWeddings.mostrar_bodas() << endl;
                break;
            }

            case 'b': {
                int tipo = elegir_paquete();
                Boda nueva_boda = crear_boda(tipo);
                
                QroWeddings.agregar_boda(nueva_boda); 
                cout << "Boda registrada" << endl;
                break;
            }

            case 'c': {
                int position = buscar_boda(QroWeddings);
                consultar_info(QroWeddings, position);

                if (position == -1) {
                    break;
                } else {
                    
                    bool submenu = true;
                    while (submenu) {
                        char choice2 = menu2();
                        switch (choice2) {
                            case 'a' : {
                                mostrar_invitados(QroWeddings, position);
                                break;
                            }
                            case 'b': {
                                agregar_invitado(QroWeddings, position);
                                break; 
                            }

                            case 'c' : {
                                cotizar(QroWeddings, position);
                                break;
                            }

                            case 'd': {
                                cout << "Regresando al menu principal..." << endl;
                                submenu = false;
                                break;
                            }
                            default : 
                                cout << "Opcion invalida" << endl;
                        }
                    }
                }
                break;
            }

            case 'd': {
                cout << "¡Hasta luego!" << endl;
                return 0;
            }

            default:
                cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}

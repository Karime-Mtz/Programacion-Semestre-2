/*
 * Proyecto Wedding Planner
 * Karime Martínez López
 * A01709690
 * 12/06/2026
 */

/**
 * Este programa simula una empresa que se dedica a organizar bodas 
 * necesita un programa que la ayude a llevar una buena administración 
 * de estos eventos. Este sistema lleva un registro de las bodas a 
 * través de un menu. Incluye la administración del nombre de los 
 * novios, el lugar en el que se llevará a cabo y la fecha.
*/

// Bibliotecas
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>

using namespace std;

// Tipos de objetos que utiliza el proyecto
#include "Invitado.h"
#include "Paquete.h"
#include "Basico.h"
#include "Premium.h"
#include "Boda.h"
#include "Empresa.h"

// Procedimiento menu
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

// Procedimiento submenu
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

/**
 * Función que recorre cada caracter del string 
 * y lo convierte a minusculas
 *
 * @param string s: texto que quiere ser pasado a minusculas
 * @return string s: texto en minusculas
 */
string a_minusculas(string s) {
    // c es una referencia del caracter actual de s
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

/**
 * Función que busca una boda específica dentro del arreglo de la empresa
 *
 * @param Empresa &empresa: referencia a la empresa en el catálogo,
 * string novia: nombre de la novia, string novio: nombre del novio 
 * @return int: índice de la posición en el arreglo o -1 si no se encuentra
 */
int posicion_boda(Empresa &empresa, string novia, string novio) {
    string nombre_buscado;
    novio = a_minusculas(novio);
    novia = a_minusculas(novia);
    nombre_buscado = novia + "_" + novio; 

    for (int i = 0; i < empresa.get_num_bodas(); i++) {

        // Compara el nombre de la boda con el que se crea con los parametros
        if (empresa.get_boda(i).get_nombre() == nombre_buscado) {
            return i;
        }
    }
    return -1;
}

/**
 * Función que muestra el menú de selección de paquetes y valida 
 * que el usuario ingrese una opción correcta
 *
 * @return int tipo: número que representa el paquete elegido
 */
int elegir_paquete() {
    int tipo;
    cout << "¿Que paquete te gustaria? (1/2)\n"
    "1.- Basico\n2.- Premium\n";

    // Se asegura que la respuesta sea válida
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

/**
 * Función que pregunta al usuario si desea incluir algún servicio
 *
 * @param string servicio: nombre del servicio
 * @return bool: true si el usuario acepta el servicio, false si lo rechaza
 */
bool elegir_servicio(string servicio) {
    int opcion;
    cout << "¿Te gustaría agregar el servicio de " << servicio << "? (1/2)\n"
    "1.- Si\n2.- No\n";

    // Asegura que la opcion sea valida
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

/**
 * Función que inicializa los costos y junta las preferencias del usuario
 * para construir un paquete Básico
 *
 * @return Basico: objeto de tipo Basico
 */
Basico crear_paquete_basico(){
    float precio_base = 80000.0;
    bool decoracion = elegir_servicio("decoracion");
    bool dj = elegir_servicio("musica de DJ");
    bool buffet = elegir_servicio("buffet");

    Basico paquete_basico(precio_base, decoracion, dj, buffet);
    return paquete_basico;
}

/**
 * Función que inicializa los costos y junta las preferencias del usuario
 * para construir un paquete Premium
 *
 * @return Premium: objeto de tipo Premium 
 */
Premium crear_paquete_premium(){
    float precio_base = 80000.0;
    bool decoracion = elegir_servicio("decoracion");
    bool vivo = elegir_servicio("musica en vivo");
    bool tres_t = elegir_servicio("comida de tres tiempos");
    bool fotos = elegir_servicio("fotografías");

    Premium paquete_premium(precio_base, decoracion, vivo, tres_t, fotos);
    return paquete_premium;
}

/**
 * Función que recopila los datos generales de una celebración y manda a construir 
 * su respectivo paquete de servicios según la elección del usuario
 *
 * @param int tipo: indicador del tipo de paquete 
 * @return Boda: objeto Boda listo para ser ingresado al catalogo
 */
Boda crear_boda(int tipo) {
    string novia, novio, fecha, lugar;
    float presupuesto;

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
    cin.ignore(); // Limpiamos el buffer del presupuesto

    if (tipo == 1){
        // Creamos el objeto en el heap
        Basico* paqueteB = new Basico(crear_paquete_basico());
        return Boda(novia, novio, lugar, fecha, presupuesto, paqueteB);
    } else {
        // Creamos el objeto en el heap
        Premium* paqueteP = new Premium(crear_paquete_premium());
        return Boda(novia, novio, lugar, fecha, presupuesto, paqueteP);
    }
}

/**
 * Función que solicita al usuario los nombres de los novios
 * para localizar la posicion de una boda en el catalogo
 *
 * @param Empresa &empresa: referencia a la empresa donde se realizará la búsqueda
 * @return int: índice de la posición devuelto por la función posicion_boda
 */
int buscar_boda(Empresa &empresa){
    string novia, novio;
    cout << "¿Cual es el nombre de la novia?" << endl;
    getline(cin, novia);
    cout << "¿Cual es el nombre del novio?" << endl;
    getline(cin, novio);

    int position = posicion_boda(empresa, novia, novio);
    return position;
}

/**
 * Función que imprime los detalles de la boda si el índice que se da
 * es válido
 *
 * @param Empresa &empresa: referencia a la empresa que contiene los registros
 * @param int position: posición de la boda dentro del arreglo estático
 */
void consultar_info(Empresa &empresa, int position){

    if (position == -1) {
        cout << "No se encontro la boda" << endl;
    } else {
        // Imprime los datos usando el método del objeto libro
        cout << empresa.get_boda(position).mostrar_detalles();
    }
}

/**
 * Función que muestra la listade todos los invitados registrados 
 *
 * @param Empresa &empresa: referencia a la empresa que contiene la boda seleccionada
 * @param int position: índice de la boda de la cual se quieren auditar los invitados
 */
void mostrar_invitados(Empresa &empresa, int position){
    if (position == -1) {
        cout << "No se encontro la boda" << endl;
    } else {
        cout << empresa.get_boda(position).mostrar_invitados() << endl;
    }
}

/**
 * Función que recopila los datos de un invitado y lo agrega a la lista
 *
 * @param Empresa &empresa: referencia a la empresa
 * @param int position: índice de la boda a la cual se registrara el invitado
 */
void agregar_invitado(Empresa &empresa, int position){
     if (position == -1) {
        cout << "No se encontro la boda" << endl;
        return;
    }
    
    string invitado;
    int acomp;

    cout << "\nNombre del invitado: ";
    getline(cin, invitado);

    cout << "¿Tiene acompanante? (1/2)" << endl;
    cout << "1.- Si" << endl;
    cout << "2.- No" << endl;

    // Asegura que la respuesta sea válida
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

/**
 * Función que calcula el costo total de una boda, a través de una funcion
 * que utiliza polimorfismo y comparara con el presupuesto del cliente
 *
 * @param Empresa &empresa: referencia a la empresa
 * @param int position: índice de la boda
 */
void cotizar(Empresa &empresa, int position){
    if (position == -1) {
        cout << "No se encontro la boda" << endl;
    } else {
        Boda &boda_actual = empresa.get_boda(position);
        cout << "Costo de la boda: " << boda_actual.calcular_costo_boda() << endl;
        cout << "Presupuesto inicial: " << boda_actual.get_presupuesto() << endl;
    }
}


int main() {

// Creación de empresa
Empresa QroWeddings("Qro Weddings");

// Creación de los apuntadores a los paquetes en memoria heap
Basico* paqueteLago = new Basico(30000, true, true, true);
Basico* paqueteSalon = new Basico(30000, true, false, true);
Premium* paqueteVinedo = new Premium(30000, true, true, false, true);

// Creación de las Bodas
Boda Isabela_Esteban("Isabela", "Esteban", "Lago de las Canadas", "15/07/2023", 180000.0, paqueteLago);
Boda Erica_Juan("Erica", "Juan Pablo", "Salon Tulipanes", "01/02/2021", 165000.0, paqueteSalon);
Boda Aurora_Mauricio("Aurora", "Mauricio", "Vinedo del norte", "25/11/2023", 230000.0, paqueteVinedo);

// Agregar las bodas al catálogo de la empresa
QroWeddings.agregar_boda(Isabela_Esteban);
QroWeddings.agregar_boda(Erica_Juan);
QroWeddings.agregar_boda(Aurora_Mauricio);

// Permite realizar varias acciones hasta que se salga del programa
while (true) {
        // Muestra el menu principial y recibe la opcion elegida
        char choice = menu();

        // Ejecuta las funciones de acuerdo a la opcion elegida
        switch (choice) {
            case 'a': {
                // Muestra el catalogo con las bodas
                cout << QroWeddings.mostrar_bodas() << endl;
                break;
            }

            case 'b': {
                // se crea el paquete
                // se crea una boda y se le asigna el paquete generado
                int tipo = elegir_paquete();
                Boda nueva_boda = crear_boda(tipo);
                
                // se agrega la boda al catálogo de la empresa
                QroWeddings.agregar_boda(nueva_boda); 
                cout << "Boda registrada" << endl;
                break;
            }

            case 'c': {
                // se busca la posicion de la boda en el arreglo
                // se muestra la informacion de la boda encontrada
                int position = buscar_boda(QroWeddings);
                consultar_info(QroWeddings, position);

                if (position == -1) {
                    break;
                } else {
                    
                    // si se encuentra la boda se despliega un submenu 
                    // con acciones específicas para la boda
                    bool submenu = true;
                    while (submenu) {
                        char choice2 = menu2();
                        switch (choice2) {
                            case 'a' : {
                                // muestra la lista de invitados
                                mostrar_invitados(QroWeddings, position);
                                break;
                            }
                            case 'b': {
                                // agrega a un invitado a la lista
                                agregar_invitado(QroWeddings, position);
                                break; 
                            }

                            case 'c' : {
                                // compara el costo con el presupuesto inicial
                                cotizar(QroWeddings, position);
                                break;
                            }

                            case 'd': {
                                // regresa al menu principal
                                cout << "Regresando al menu principal..." << endl;
                                submenu = false;
                                break;
                            }
                            default : 
                                // en caso de que el usuario elija una opcion no valida
                                cout << "Opcion invalida" << endl;
                        }
                    }
                }
                break;
            }

            case 'd': {
                // en caso de que el usuario elija una opcion no valida
                cout << "¡Hasta luego!" << endl;
                return 0;
            }

            default:
                cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}

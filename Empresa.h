/*
 * Proyecto Wedding Planner
 * Karime Martínez López
 * A01709690
 * 12/06/2026
 */

 /*
 * Clase Empresa contiene los métodos genéricos para el manejo de sus
 * atributos y mantiene un registro de las bodas.
 *
 */

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Declaracion de clase Empresa
class Empresa {

    // Declaracion de variables de instancia
    private:
        string brand;
        Boda lista_bodas[50];
        int num_bodas;

    // Declaracion de los métodos del objeto
    public:
        Empresa();
        Empresa(string b);
        string get_brand();
        int get_num_bodas();
        void agregar_boda(Boda &wedding);
        string mostrar_bodas();
        Boda& get_boda(int posicion);
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Empresa
 */
Empresa::Empresa(){
    brand = "";
    num_bodas = 0;
}

/**
 * Constructor recibe valores para llenar las variables de instancia
 *
 * @param string b: nombre de la marca
 * @return objeto Empresa
 */
Empresa::Empresa(string b){
    brand = b;
    num_bodas = 0;
}

/**
 * getter brand
 *
 * @param
 * @return string: nombre de la marca
*/
string Empresa::get_brand(){
    return brand;
}

/**
 * getter numero de bodas
 *
 * @param
 * @return string: cantidad de bodas registradas
*/
int Empresa::get_num_bodas(){
    return num_bodas;
}

/**
 * Agrega una boda a la lista si no se ha alcanzado el límite
 *
 * @param Boda &wedding: referencia a una boda existente
 * @return boda registrada en la lista y actualización del numero de bodas
*/
void Empresa::agregar_boda(Boda &wedding){
    if (num_bodas >= 50) {
        cout << "Máximo número de Bodas alcanzado" << endl;
    } else {
        lista_bodas[num_bodas] = wedding;
        num_bodas++;
    }
}

/**
 * Muestra los atributos de cada una de las bodas en la lista a través de 
 * stringstream
 *
 * @param
 * @return string con la información de cada boda
*/
string Empresa::mostrar_bodas(){
    stringstream lista;
    lista << "Bodas registradas actualmente: " << num_bodas << endl;
    for (int i = 0; i < num_bodas; i++){
        lista << "\nBoda " << i+1 << endl;
        lista << lista_bodas[i].get_nombre() << endl;
        lista << lista_bodas[i].get_novio() << endl;
        lista << lista_bodas[i].get_novia() << endl;
        lista << lista_bodas[i].get_lugar() << endl;
        lista << lista_bodas[i].get_fecha() << endl;
    }
    return lista.str();
}

/**
 * getter boda
 *
 * @param int posicion: posicion de la boda en la lista
 * @return referencia a una boda ya existente
*/
Boda& Empresa::get_boda(int posicion) {
   
    if (posicion < 0 || posicion >= num_bodas) {
        cout << "Error: Índice de boda fuera de rango." << endl;
        
        return lista_bodas[0]; 
    }
    
    return lista_bodas[posicion];
}

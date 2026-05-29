#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Empresa {

    private:
        string brand;
        Boda lista_bodas[50];
        int num_bodas;

    public:
        Empresa();
        Empresa(string b);
        string get_brand();
        int get_num_bodas();
        void agregar_boda(Boda &wedding);
        string mostrar_bodas();
        Boda& get_boda(int posicion);
};


Empresa::Empresa(){
    brand = "";
    num_bodas = 0;
}

Empresa::Empresa(string b){
    brand = b;
    num_bodas = 0;
}

string Empresa::get_brand(){
    return brand;
}

int Empresa::get_num_bodas(){
    return num_bodas;
}

void Empresa::agregar_boda(Boda &wedding){
    if (num_bodas >= 50) {
        cout << "Máximo número de Bodas alcanzado" << endl;
    } else {
        lista_bodas[num_bodas] = wedding;
        num_bodas++;
    }
}

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

Boda& Empresa::get_boda(int posicion) {
   
    if (posicion < 0 || posicion >= num_bodas) {
        cout << "Error: Índice de boda fuera de rango." << endl;
        
        return lista_bodas[0]; 
    }
    
    return lista_bodas[posicion];
}

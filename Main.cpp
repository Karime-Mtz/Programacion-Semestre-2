#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "Invitado.h"
#include "Paquete.h"
#include "Basico.h"
#include "Premium.h"
#include "Boda.h"
#include "Empresa.h"

int main() {

// Creación de empresa
Empresa QroWeddings("Qro Weddings");

// Creación de paquetes
Basico PaqueteBodaLago(30000, true, true, true);
Basico PaqueteSalon(30000, true, false, true);
Premium PaqueteBodaViñedo(30000, true, true, false, true);

// Creación de Bodas
Boda BodaLago("Isabela","Esteban", "Lago de las Canadas", "15/07/2023", 180000.0, PaqueteBodaLago);
Boda BodaSalon("Erica", "Juan Pablo", "Salon Tulipanes", "01/02/2021", 165000.0, PaqueteSalon);
Boda BodaViñedo("Aurora", "Mauricio", "Vinedo del norte", "25/11/2023", 230000.0, PaqueteBodaViñedo);

cout << "Numero de bodas realizadas" << endl;
QroWeddings.agregar_boda(BodaLago);
QroWeddings.agregar_boda(BodaSalon);
QroWeddings.agregar_boda(BodaViñedo);
cout << QroWeddings.get_num_bodas() << endl;

cout << "Bodas: " << endl;
cout << QroWeddings.mostrar_bodas() << endl;

cout << "Novio Boda Salon" << endl;
cout << BodaSalon.get_novio() << endl;
cout << "Num de invitados" << endl;
cout << BodaSalon.get_num_invitados() << endl;
BodaSalon.agregar_invitado("Raul", true);
BodaSalon.agregar_invitado("Isaac", true);
BodaSalon.agregar_invitado("Shirley", false);

cout << "Actualizacion invitados" << endl;
cout << BodaSalon.mostrar_invitados() << endl;
cout << BodaSalon.get_num_invitados() << endl;

cout << "Presupuesto de Boda Vinedos" << endl;
cout << BodaViñedo.get_presupuesto() << endl;
BodaViñedo.set_presupuesto(210000);
cout << BodaViñedo.get_presupuesto() << endl;
cout << BodaViñedo.get_tipo_paquete()<< endl;

cout << "Precio Paquete boda vinedo" << endl;
cout << PaqueteBodaViñedo.calcular_precio() << endl;


cout << "Precio Boda Lago" << endl;
cout << BodaLago.calcular_costo_boda() << endl;

return 0;
}

# Programacion-Semestre-2

## Contexto
Una empresa que se dedica a organizar bodas necesita un programa que la ayude a llevar una buena administración de estos eventos. Este sistema lleva un registro de las bodas a través de un menu. Incluye la administración del nombre de los novios, el lugar en el que se llevará a cabo y la fecha. 
#### Menu:
* a) Mostrar todas las bodas
* b) Registrar nueva boda
* c) Consultar informacion de una boda

También permite manejar las bodas de manera individual. Se le brinda la opción al usuario de checar la lista de invitados, agregar nuevos, al igual que cotizar el evento.
#### Submenu:
* a) Mostrar lista de invitados
* b) Agregar invitado
* c) Cotizar boda

## Clase Abstracta
La clase abstracta es Paquete, ya que el programa solo permite crear objetos de sus clases 'hijas': Basico y Premium.
Se declaró abastracta por medio del método calcular_precio(), el cual se sobreescribe en las clases hereditarias.

## Polimorfismo
En mi proyecto el polimorfismo está presente en la clase Boda, en el método calcular_costo_boda().

## Casos que harían que el proyecto deje de funcionar
- La lista de bodas y la lista de invitados tienen un tamaño fijo en el almacenamiento. No se debe rebasar.
- Punteros que accedan a la memoria dinámica y no sean borrados una vez que cumplieron su función, pueden llenar la memoria de basura.
- La función 'cin' es sumamente sensible y si el código no se limpia continuamente puede entrar en un bucle infinito.

## Instrucciones
Compilar con: `g++ Main.cpp -o main`

Correr en windows: `.\/main.exe`

#include <iostream>
#include <string>
#include "Interfaz.hpp"
#include "Agenda.hpp"
#include "Contacto.hpp"
#include "GestorDB.hpp"
#include "GestorDBFichero.hpp"

using namespace std;
using namespace agenda;


int main(int argc, char**argv) {

	cout << "Hola mundo." << endl;

	//COMENTADO PARA QUITAR FALLOS REDUNDANTES

	string nombre = "nombre.txt";

	GestorDBFichero *g = new GestorDBFichero(nombre);


	Agenda a(g);
	Interfaz i();

	//SOBRECARGAR OPERADORES = EN AGENDA

	return 0;
}

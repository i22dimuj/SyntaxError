#include <iostream>
#include <string>
#include "Interfaz.hpp"
#include "Agenda.hpp"
#include "Contacto.hpp"
#include "GestorDB.hpp"
#include "GestorDBFichero.hpp"

using namespace std;

int main(int argc, char**argv) {


	string nombre;
	cout << "Introduzca el nombre del fichero a cargar: ";
	cin >> nombre;
	GestorDBFichero *g = new GestorDBFichero(nombre);
	Agenda a(g);

	cout << "Nombre fichero : " << a.getFichero() << endl;

	a.getGestorDB()->cargar(a.getFichero());

	Interfaz i(a);

	i.menuAgenda();

	//SOBRECARGAR OPERADORES = EN AGENDA

	return 0;
}

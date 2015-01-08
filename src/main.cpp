#include <iostream>
#include <string>
#include "Interfaz.hpp"
#include "Agenda.hpp"
#include "Contacto.hpp"
#include "GestorDB.hpp"
#include "GestorDBFichero.hpp"

using namespace std;

int main(int argc, char**argv) {

	//COMENTADO PARA QUITAR FALLOS REDUNDANTES

	string nombre = "nombre.txt";
	GestorDBFichero *g = new GestorDBFichero(nombre);
	Agenda a(g);

	Interfaz i(a);

	i.menuAgenda();

	//SOBRECARGAR OPERADORES = EN AGENDA

	return 0;
}

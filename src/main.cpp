#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "Interfaz.hpp"
#include "Agenda.hpp"
#include "Contacto.hpp"
#include "GestorDB.hpp"
#include "GestorDBFichero.hpp"

using namespace std;

int main() {

	system("clear");
	string nombre = "agenda.txt";
	cout << "El archivo donde se guardará la agenda es: " << nombre;
	getchar();

	GestorDBFichero *g = new GestorDBFichero(nombre);
	Agenda a(g);

	ifstream file(nombre.c_str());

	if(not file.is_open())
		ofstream fichero(nombre.c_str());


	a.setContactos(a.getGestorDB()->cargar(a.getFichero()));

	Interfaz i(a);

	i.menuAgenda();

	//SOBRECARGAR OPERADORES = EN AGENDA

	return 0;
}

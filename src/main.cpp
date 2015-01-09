#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include "Interfaz.hpp"
#include "Agenda.hpp"
#include "Contacto.hpp"
#include "GestorDB.hpp"
#include "GestorDBFichero.hpp"

using namespace std;

int main() {


	string nombre = "agenda.txt";
	cout << "El archivo donde se guardará la agenda es: " << nombre << endl;
	getchar();

	GestorDBFichero *g = new GestorDBFichero(nombre);
	Agenda a(g);

	ifstream file(nombre.c_str());

	if(not file.is_open())
		ofstream fichero(nombre.c_str());


	a.getGestorDB()->cargar(a.getFichero());

	Interfaz i(a);

	i.menuAgenda();

	//SOBRECARGAR OPERADORES = EN AGENDA

	return 0;
}

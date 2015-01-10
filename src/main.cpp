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

	ifstream file(nombre.c_str());

	if(not file.is_open())
	{
		cout << "no se ha encontrado \"agenda.txt\". Introduzca el nombre del fichero de la base de datos, o dejelo en blanco para crear una nueva base de datos" << endl;
		cout << "Fichero: ";
		getline(cin, nombre);
		if (nombre == "")
		{
			nombre = "agenda.txt";
			ofstream fichero(nombre.c_str());
		}
		else
		{
			ifstream file(nombre.c_str());
		}
	}

	GestorDBFichero *g = new GestorDBFichero(nombre);
	Agenda a(g);


	a.setContactos(a.getGestorDB()->cargar(a.getFichero()));

	Interfaz i(a);

	i.menuAgenda(nombre);

	//SOBRECARGAR OPERADORES = EN AGENDA

	return 0;
}

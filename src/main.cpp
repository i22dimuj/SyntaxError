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
	string copiaSeguridad = "copiaSeguridad.txt";

	ifstream file(nombre.c_str());

	if(not file.is_open())
	{
		ifstream file(copiaSeguridad.c_str());

		if(not file.is_open())
		{
			ofstream fichero(nombre.c_str());
			cout << "Se ha creado una nueva base de datos (pulse enter para continuar)" << endl;
			getchar();
		}
		else
		{
			ifstream file(copiaSeguridad.c_str());
			nombre = copiaSeguridad;
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

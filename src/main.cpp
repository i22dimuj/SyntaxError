#include <iostream>
#include "Interfaz.hpp"
#include "Agenda.hpp"
#include "Contacto.hpp"

using namespace std;
using namespace agenda;


int main(int argc, char**argv) {
	GestorDBFichero* g = new GestorDBFichero("nombre.txt");

	Agenda a = new Agenda(g);

	return 0;
}

#include <iostream>
#include "Contacto.hpp"
#include <list>

using namespace std;

Contacto::Contacto() {
	_favorito = false;
	_frecuente = 0;
	_nombre = "";
	_apellido1 = "";
	_apellido2 = "";
	_dni = "";
}

Contacto::Contacto(string dni, string nombre, string apellido1, string apellido2, string telefono) {
	_dni = dni;
	_nombre = nombre;
	_apellido1 = apellido1;
	_apellido2 = apellido2;
	_telefono.push_back(telefono);
	_favorito = false;
	_frecuente = 0;
}

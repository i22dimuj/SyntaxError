#include <iostream>
#include <list>
#include "Contacto.hpp"
#include "Agenda.hpp"

using namespace std;
namespace agenda {

Agenda::Agenda(GestorDB* g) {
	_bd = g;
}

bool Agenda::guardar() {
	_bd->guardar();
	return true;
}

bool Agenda::insertar(Contacto contacto) {

	if(_contactos.push_back(contacto))  //Hacer el sort dentro del if
	{
		//Ordenar por apellido
		return true;
	} else {
		return false;
	}
}

list <Contacto> Agenda::buscar(string apellido1) {
	int encontrados = 0;
	list <Contacto> aux;

	for(list <Contacto>::iterator iter = _contactos.begin(); iter != _contactos.end(); iter++) {
		if(iter->getApellido1() == apellido1) {
			aux.push_back(*iter);
			encontrados++;
		}
	}

	if(encontrados == 0)	//Devolver un error si no se encuentra nada???
		return NULL;

	return aux;
}

bool Agenda::borrar(string dni) {
	for(list <Contacto>::iterator iter = _contactos.begin(); iter != _contactos.end(); iter++) {
		if(iter->getDNI() == dni) {
			//eliminar contacto con dni
			return true;
		}
	}
  return false;
}

}

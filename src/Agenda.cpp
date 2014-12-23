#include <iostream>
#include <list>
#include "Agenda.hpp"


using namespace std;
namespace agenda {


agenda::Agenda::Agenda(GestorDB* g) {
	_bd = g;
}

bool agenda::Agenda::guardar() {
	_bd->guardar();
	return true;
}

bool Agenda::insertar(Contacto contacto) {

	if(_contactos.push_back(contacto))  //Hacer el sort dentro del if
	{
		
	}
	else
		return false;


  return true;
	
}

list Agenda::buscar(string apellido1){

  int encontrados = 0;
  list <Contacto> aux;
  list <Contacto>::iterator iter;


	for(iter = _contactos.begin(); iter != _contactos.end(); iter++){

		if(iter->getApellido1() == apellido1){
			aux.push_back(*iter);
			encontrados++;
		}
	}

	if(encontrados == 0)	//Devolver un error si no se encuentra nada???
		return NULL;


  return aux;

}

bool Agenda::borrar(string dni){


  list <Contacto>::iterator iter;


	for(iter = _contactos.begin(); iter != _contactos.end(); iter++){

		if(iter->getDNI() == dni){
			iter->erase();
		  return true;
		}
	}

  return false;
}

}

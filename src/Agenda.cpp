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
		ordenaAgenda(_contactos); //Ordenar por apellido
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

	if (encontrados == 0)
	{
		return NULL;
	}

	return aux;
}

bool Agenda::borrar(string dni) {
	for(list <Contacto>::iterator iter = _contactos.begin(); iter != _contactos.end(); iter++) {
		if(iter->getDNI() == dni) {
			_contactos.erase(iter);//eliminar contacto con dni
			return true;
		}
	}
  return false;
}

bool comparaContactos(Contacto &a, Contacto &b)
{
	return a.getApellido1() < b.getApellido1();
}

void ordenaAgenda(list <Contacto> lista)
{
	lista.sort(comparaContactos);
}

bool Agenda::modificar(Contacto contactoViejo, Contacto contactoNuevo)
{
	if (contactoNuevo.getNombre() == "")
	{
		contactoNuevo.setNombre(contactoViejo.getNombre());
	}
	if (contactoNuevo.getApellido1() == "")
	{
		contactoNuevo.setApellido1(contactoViejo.getApellido1());
	}
	if (contactoNuevo.getApellido2() == "")
	{
		contactoNuevo.setApellido2(contactoViejo.getApellido2());
	}
	if (contactoNuevo.getDNI() == "")
	{
		contactoNuevo.setDNI(contactoViejo.getDNI());
	}
	/* Hay que hacerlo de otra forma
	if (contactoNuevo.getTelefono() == "")
	{
		contactoNuevo.addTelefono(contactoViejo.getTelefono());
	}
	*/
	return false;
}


}

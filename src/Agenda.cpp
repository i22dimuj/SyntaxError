#include <iostream>
#include <list>
#include <algorithm> //Para buscar en la lista
#include "Contacto.hpp"
#include "Agenda.hpp"

using namespace std;

Agenda::Agenda(GestorDB* g) {
	_bd = g;
}

Agenda::Agenda(Agenda &agenda) {

	fichero = agenda.getFichero();
	_bd = agenda.getGestorDB();
	_contactos = agenda.getContactos();
	_frecuentes = agenda.getFrecuentes();
}

bool Agenda::guardar() {
	if(_bd->guardar(_contactos))
		return true;
	else
		return false;
	return false;
}
bool Agenda::insertar(Contacto contacto) {

	// ARREGLAR
	//Si la lista esta vacia se inserta el elemento
	if(_contactos.empty()) {
		_contactos.push_back(contacto);
		return true;
	//Si el contacto no esta en la lista la funcion find devuelve la última posicion
	} else if(!existeDNI(contacto.getDNI())) {	//Hacer el sort dentro del if
		_contactos.push_back(contacto);
		ordenaAgenda(_contactos); 				//Ordenar por apellido
		return true;
	} else {
		return false;
	}

	return true; // Cambiar
}

list <Contacto> Agenda::buscar(string apellido1) {
	
	list <Contacto> aux;

	for(list <Contacto>::iterator iter = _contactos.begin(); iter != _contactos.end(); iter++) {
		if(iter->getApellido1() == apellido1) {
			aux.push_back(*iter);
			iter->buscado();	//Incrementamos el numero de _frecuente
			actualizarFrecuentes(*iter);  //actualizamos la lista de frecuentes
		}
	}

	return aux;
}

bool Agenda::borrar(string dni) {

	for(list <Contacto>::iterator iter = _contactos.begin(); iter != _contactos.end(); iter++) {
		if(iter->getDNI() == dni) {
			_contactos.erase(iter);//eliminar contacto con dni
			//Eliminamos contacto de lista de frecuentes (si existe)
			for(list <Contacto>::iterator iterf = _frecuentes.begin(); iterf != _frecuentes.end(); iterf++)
				if(iterf->getDNI() == dni)
					_frecuentes.erase(iterf);
			return true;
		}
	}
	return false;
}

bool Agenda::comparaContactos(const Contacto &a, const Contacto &b)
{
	return a.getApellido1() < b.getApellido1();
}

void Agenda::ordenaAgenda(list <Contacto> lista)
{
	//lista.sort(comparaContactos); No Funka :'(
}

//Se llama con un contacto ya relleno y se iguala al viejo
bool Agenda::modificar(Contacto contactoViejo, Contacto contactoNuevo)
{
	if (contactoNuevo.getNombre() == "")
		contactoNuevo.setNombre(contactoViejo.getNombre());
	if (contactoNuevo.getApellido1() == "")
		contactoNuevo.setApellido1(contactoViejo.getApellido1());
	if (contactoNuevo.getApellido2() == "")
		contactoNuevo.setApellido2(contactoViejo.getApellido2());
	if (contactoNuevo.getDNI() == "")
		contactoNuevo.setDNI(contactoViejo.getDNI());

	//Elimina la lista anterior de telefonos, se sustituye por la nueva  ???
	// ARREGLAR
#if 0
	for (list <Contacto>::iterator iter = contactoViejo.begin(); iter != contactoViejo.end(); iter++)  {
		if (contactoNuevo.getTelefono() == "") {
			contactoNuevo.removeTelefono();
			contactoNuevo.addTelefono(contactoViejo.getTelefono());
		}

		//Estas dos no serían con this. ???
		this->borrar(contactoViejo.getDNI());
		this->insertar(contactoNuevo);
	}
#endif

	return true;
}


void Agenda::actualizarFrecuentes (Contacto frecuente)
{
/*	if(_frecuentes.empty())
		_frecuentes.push_back(frecuente);

	list <Contacto>::iterator iter_aux;
	int encontrado = 0;

	for (list <Contacto>::iterator iter = _frecuentes.begin(); iter != _frecuentes.end(); iter++) {
		if(iter->getDNI() == frecuente.getDNI()) {
			iter->buscado();  //frecuente++ en lista de frecuentes
			encontrado = 1;		//Para que sirve encontrado?
			iter_aux = iter--;
			if (iter->numeroBusquedas() > iter_aux->numeroBusquedas())
				ordenaAgenda(_frecuentes);
		}
	}

	if(encontrado == 0)	//Si no esta en la lista, se añade
		_frecuentes.push_back(frecuente);
	*/
}

bool Agenda::existeDNI(string DNI)
{
	list <Contacto>::iterator iter;

	for (iter = _contactos.begin(); iter != _contactos.end(); iter++)
	{
		if (iter->getDNI() == DNI)
			return true;
	}
	return false;

}

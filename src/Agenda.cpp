#include <iostream>
#include <list>
#include "Contacto.hpp"
#include "Agenda.hpp"

using namespace std;
namespace agenda {

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
			iter->buscado();	//Incrementamos el numero de _frecuente
			actualizarFrecuentes(*iter);  //actualizamos la lista de frecuentes
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

  list <Contacto>::iterator iterf;

	for(list <Contacto>::iterator iter = _contactos.begin(); iter != _contactos.end(); iter++) {
		if(iter->getDNI() == dni) {
			_contactos.erase(iter);//eliminar contacto con dni

			
			//Eliminamos contacto de lista de frecuentes (si existe)
			for(iterf = _frecuentes.begin(); iterf != _frecuentes.end(); iterf++) {
				if(iterf->getDNI() == dni)

					_frecuentes.erase(iterf);	
			}

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
	borrar(contactoViejo.getDNI());
	insertar(contactoNuevo);

	return true;
}


void actualizarFrecuentes(Contacto frecuente)
{

	if(_frecuentes.empty())
		_frecuentes.push_back(frecuente);

	
  list <Contacto>::iterator iter;

	for(iter = _frecuentes.begin(); iter != _frecuentes.end(); iter++){

		if(iter->getDNI() == frecuente.getDNI()){

			iter->buscado();  //frecuente++ en lista de frecuentes
			
		  list <Contacto>::iterator iter_aux;

			iter_aux = (iter-1);

			if(iter->getFrecuente() > iter_aux->getFrecuente()){  //Si al aumentar el numero de busquedas, supera al anterior, hay que reordenar la lista de frecuentes ¿Como se hace?



			}				
		}
	}
}

}

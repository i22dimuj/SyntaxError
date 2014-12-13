#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <iostream>
#include <list>
#include <string>

#include "Contacto.hpp"

class Agenda
{
private:
	std::list <Contacto> _contactos;
	std::list <Contacto> _frecuentes;

public:
	Agenda(){};
	Agenda(Agenda::agenda){};
	/*
	 * buscar
	 * insertar
	 * borrar
	 * modificar
	 */


};
#endif

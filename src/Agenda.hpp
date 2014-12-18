#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <iostream>
#include <list>
#include <string>

#include "Contacto.hpp"

namespace agenda {

class Agenda {
	private:
		std::list <Contacto> _contactos;
		std::list <Contacto> _frecuentes;
		std::string fichero;

	public:
		Agenda();
		Agenda(Agenda &agenda);
		/*
		 * buscar
		 * insertar
		 * borrar
		 * modificar
		 */


};
}
#endif

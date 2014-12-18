#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <iostream>
#include <list>
#include <string>

#include "Contacto.hpp"
#include "GestorDB.hpp"

namespace agenda {

class Agenda {
	private:
		std::string fichero;
		std::list <Contacto> _contactos;
		std::list <Contacto> _frecuentes;
		GestorDB* _bd;

	public:
		Agenda(GestorDB* g);
		Agenda(Agenda &agenda);

		std::list <Contacto> buscar(std::string apellido1);
		bool insertar(Contacto contacto);
		bool borrar(std::string apellido1);
		bool modificar(Contacto contacto);
		bool guardar(); //Copia de seguridad ¿?
};
}
#endif

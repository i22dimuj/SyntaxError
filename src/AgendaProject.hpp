#ifndef AGENDAPROJECT_HPP
#define AGENDAPROJECT_HPP

#include <iostream>
#include <Contacto.hpp>
#include <list>
#include <string>

class Agenda
{
private:
	std::list <Contacto> _pacientes;

public:
	std::list <Contacto> buscar(std::string apellido);
	bool insertarContacto(Contacto contacto);
	bool eliminarContacto(std::string apellido);
	bool modificarContacto(std::string apellido);
	void guardarFichero(std::list <Contacto> _paciente);

};
#endif

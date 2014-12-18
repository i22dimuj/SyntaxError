#ifndef INTERFAZ_HPP
#define INTERFAZ_HPP
#include <iostream>
#include "Agenda.hpp"
#include "Contacto.hpp"

namespace agenda {

class Interfaz: public Agenda
{
private:

public:
	void iniciarAgenda(); //Inicia la agenda (graficamente)
	int menuAgenda();
	bool menuFuncion(int opc); //Devuelve FALSE si no se quiere salir, si se quiere salir devuelve TRUE
	void imprimirAgenda();
	void verFavoritos();
	void verFrecuentes();
	//Contacto rellenarPersona() {};

};

}
#endif

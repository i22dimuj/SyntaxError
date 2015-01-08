#ifndef INTERFAZ_HPP
#define INTERFAZ_HPP

#include <iostream>
#include "Agenda.hpp"
#include "Contacto.hpp"

class Interfaz {

	private:
		Agenda _agenda;
		Contacto seleccionaContacto(std::list <Contacto> listaContactos);
		void imprimeContacto(Contacto contacto);

	public:
		Interfaz() {};
		Interfaz(Agenda &a);
		Contacto rellenarContacto();
		void menuAgenda();
		bool menuFuncion(int opc); //Devuelve FALSE si no se quiere salir, si se quiere salir 						     devuelve TRUE
		void imprimirAgenda();
		void verFavoritos();
		void verFrecuentes();
		void imprimeDireccionPostal(Contacto contacto);
		void imprimeRedSocial(Contacto contacto);

};
#endif

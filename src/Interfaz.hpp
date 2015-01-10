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
		Contacto rellenarContactoModificar();
		void menuAgenda(std::string fichero);
		bool menuFuncion(int opc);
		void imprimirAgenda();
		void verFavoritos();
		void verFrecuentes();
		direccionPostal addDireccionPostal();
		void imprimeDireccionPostal(Contacto contacto);
		redSocial addRedSocial();
		void imprimeRedSocial(Contacto contacto);
		void imprimeTelefono(Contacto contacto);
};
#endif

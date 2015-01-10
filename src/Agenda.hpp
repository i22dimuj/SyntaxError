#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <iostream>
#include <list>
#include <string>

#include "Contacto.hpp"
#include "GestorDB.hpp"

class Agenda {

	private:
		std::string fichero;
		std::list <Contacto> _contactos;
		std::list <Contacto> _frecuentes;
		GestorDB* _bd;
		bool comparaContactos(const Contacto &a, const Contacto &b);
		void ordenaAgenda(std::list <Contacto> lista);

	public:
		Agenda() {_bd = NULL;};	//Constructor vacio
		Agenda(GestorDB* g);
		Agenda(Agenda &agenda);

		std::string getFichero() {return fichero;};
		GestorDB* getGestorDB() {return _bd;};
		std::list <Contacto> getContactos() {return _contactos;};
		std::list <Contacto> getFrecuentes() {return _frecuentes;};

		//Modificadores para copiar objeto Agenda en clase Interfaz
		void setFichero(std::string fich) {fichero = fich;};
		void setGestorDB(GestorDB* bd) {_bd = bd;};
		void setContactos(std::list <Contacto> contactos) {_contactos = contactos;};
		void setFrecuentes(std::list <Contacto> frecuentes) {_frecuentes = frecuentes;};

		std::list <Contacto> buscar(std::string apellido1);
		bool insertar(Contacto contacto);
		bool borrar(std::string dni);
		bool modificar(Contacto contactoViejo, Contacto contactoNuevo);
		bool guardar(); //Copia de seguridad ¿?
		bool existeDNI(std::string DNI);
		void actualizarFrecuentes(Contacto frecuente);
};
#endif

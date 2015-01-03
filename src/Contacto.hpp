#ifndef CONTACTO_HPP
#define CONTACTO_HPP

#include <iostream>
#include <string>
#include <list>
#include "Estructuras.hpp"

namespace agenda {

class Contacto {

	private:
		std::string _nombre;
		std::string _apellido1;
		std::string _apellido2;
		std::string _dni;
		std::string _email;
		std::list <std::string> _telefono;
		std::list <redSocial> _redSocial;
		std::list <direccionPostal> _direccionPostal;
		bool _favorito;
		int _frecuente;

	public:

		//Constructores
		Contacto();
		Contacto(std::string dni, std::string nombre, std::string apellido1, std::string apellido2, std::string telefono);

		//Observadores
		std::string getNombre() {return _nombre;};
		std::string getApellido1() {return _apellido1;};
		std::string getApellido2() {return _apellido2;};
		std::string getDNI() {return _dni;};
		std::string getEmail() {return _email;};
		std::list<std::string> getTelefono() {return _telefono;};
		std::list<redSocial> getRedSocial() {return _redSocial;};
		std::list<direccionPostal> getDireccionPostal() {return _direccionPostal;};
		bool esFavorito() {return _favorito;};
		int numeroBusquedas() {return _frecuente;};

		//Modificadores
		void setNombre(std::string nombre) {_nombre = nombre;};
		void setApellido1(std::string apellido) {_apellido1 = apellido;};
		void setApellido2(std::string apellido) {_apellido2 = apellido;};
		void setDNI(std::string dni) {_dni = dni;};
		void setEmail(std::string email) {_email = email;};
		void setFrecuente(int frecuente) {_frecuente = frecuente;};

		void addTelefono(std::string telefono) {_telefono.push_back(telefono);};
		void addTelefono(std::list <std::string> telefonos) {_telefono = telefonos;}; //Sobrecargado para poder utilizarlo en modificarContato()
		void addDireccionPostal(direccionPostal direccion) {_direccionPostal.push_back(direccion);};
		void addRedSocial(redSocial red) {_redSocial.push_back(red);};
		void buscado() {_frecuente++;};
		void cambiaFavorito() { _favorito ? _favorito = false : _favorito = true;}; //if(true) _fav= false; else _fav = true;
};
}
#endif


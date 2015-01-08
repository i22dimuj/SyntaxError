/*
 * GestorDBFichero.hpp
 *
 *  Created on: 18/12/2014
 *      Author: i22caboc
 */

#ifndef GESTORDBFICHERO_HPP_
#define GESTORDBFICHERO_HPP_

#include <string>
#include <list>
#include "Agenda.hpp"
#include "GestorDB.hpp"
class GestorDBFichero : public GestorDB {

private:
	std::string _fichero;


  public:
	GestorDBFichero(){};  //Constructor vacio
	GestorDBFichero(std::string fichero) {_fichero = fichero;};
	~GestorDBFichero(){};  //Falta hacer el destructor
	bool guardar(std::list<Contacto>);
	std::list<Contacto> cargar(const std::string &fichero);
};
#endif /* GESTORDBFICHERO_HPP_ */

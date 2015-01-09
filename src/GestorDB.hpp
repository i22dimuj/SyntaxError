/*
 * GestorDB.hpp
 *
 *  Created on: 18/12/2014
 *      Author: i22caboc
 */

#ifndef GESTORDB_HPP_
#define GESTORDB_HPP_

#include <string>
#include <list>
#include "Agenda.hpp"

class GestorDB {

public:
	/* TODO: Volver a poner const */
	GestorDB() {};
	virtual ~GestorDB() {};
	virtual bool guardar(std::list<Contacto>) = 0;
	virtual std::list<Contacto> cargar(const std::string &fichero) = 0;
	virtual std::string getFichero() = 0;

};

#endif /* GESTORDB_HPP_ */

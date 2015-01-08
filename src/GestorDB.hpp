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

//class Agenda; //Hay que definir la clase aunque la definicion vaya en Agenda.hpp

namespace agenda {

class GestorDB {

public:
	/* TODO: Volver a poner const */
	GestorDB() {};
	virtual ~GestorDB() {};
	 /* virtual ~GestorDB() { std::cout << "Destructor de GestorDB" << std::endl;} //Para que no de warning*/

	virtual bool guardar(std::list<Contacto>) = 0;
	virtual std::list<Contacto> cargar(const std::string &fichero) = 0;

};

} /* namespace agenda */
#endif /* GESTORDB_HPP_ */

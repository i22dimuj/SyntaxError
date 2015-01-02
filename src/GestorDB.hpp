/*
 * GestorDB.hpp
 *
 *  Created on: 18/12/2014
 *      Author: i22caboc
 */

#ifndef GESTORDB_HPP_
#define GESTORDB_HPP_

#include <string>
#include "Agenda.hpp"

class Agenda; //Hay que definir la clase aunque la definicion vaya en Agenda.hpp

namespace agenda {

class GestorDB {

public:

	virtual bool guardar(const Agenda &a) = 0;
	virtual Agenda cargar(const std::string &fichero) = 0;
};

} /* namespace agenda */
#endif /* GESTORDB_HPP_ */

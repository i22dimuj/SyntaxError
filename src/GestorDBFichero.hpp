/*
 * GestorDBFichero.hpp
 *
 *  Created on: 18/12/2014
 *      Author: i22caboc
 */

#ifndef GESTORDBFICHERO_HPP_
#define GESTORDBFICHERO_HPP_

#include <string>
#include "Agenda.hpp"
#include "GestorDB.hpp"

namespace agenda {

class GestorDBFichero : public GestorDB {

  public:

	GestorDBFichero(){};
	~GestorDBFichero(){};
	
	bool guardar(const Agenda &a);
	Agenda cargar(const std::string &fichero);
};

} /* namespace agenda */
#endif /* GESTORDBFICHERO_HPP_ */

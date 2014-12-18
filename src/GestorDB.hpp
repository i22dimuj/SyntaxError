/*
 * GestorDB.hpp
 *
 *  Created on: 18/12/2014
 *      Author: i22caboc
 */

#ifndef GESTORDB_HPP_
#define GESTORDB_HPP_

#include "Agenda.hpp"

namespace agenda {

class GestorDB {
public:
	GestorDB();
	virtual ~GestorDB();
	virtual bool guardar(/*Agenda agenda*/);
	virtual Agenda cargar(/*std::string fichero*/);
};

} /* namespace agenda */
#endif /* GESTORDB_HPP_ */

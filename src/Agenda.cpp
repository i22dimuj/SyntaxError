#include <iostream>
#include <list>
#include "Agenda.hpp"

namespace agenda {
}

agenda::Agenda::Agenda(GestorDB* g) {
	_bd = g;
}

bool agenda::Agenda::guardar() {
	_bd->guardar();
	return true;
}

#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP

#include <string>

namespace agenda {

struct redSocial {
	std::string twitter;
	std::string facebook;
	std::string gPlus;
	std::string url;
};


struct direccionPostal {
	std::string municipio;
	std::string provincia;
	std::string calle;
	std::string portal;
	int piso;
	std::string puerta;
	int codigoPostal;
};
}
#endif
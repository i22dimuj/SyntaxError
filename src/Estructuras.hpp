#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP

#include <string>
#include <iostream>

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
	std::string piso;
	std::string puerta;
	std::string codigoPostal;
};

#endif

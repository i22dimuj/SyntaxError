#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP

#include <string>
#include <iostream>

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


void imprimeRedSocial(redSocial red){

	std::cout << "twitter: " << red.twitter << endl;
	std::cout << "facebook: " << red.facebook << endl;
	std::cout << "gPlus: " << red.gPlus << endl;
	std::cout << "url: " << red.url << endl;
}

void imprimeDireccionPostal(direccionPostal dir){

	std::cout << "Municipio: " << dir.municipio << endl;
	std::cout << "Provincia: " << dir.provincia << endl;
	std::cout << "Calle: " << dir.calle << endl;
	std::cout << "Portal: " << dir.portal << endl;
	std::cout << "Piso : " << dir.piso << endl;
	std::cout << "Puerta: " << dir.puerta << endl;
	std::cout << "Codigo Postal : " << dir.codigoPostal << endl;

}
}
#endif

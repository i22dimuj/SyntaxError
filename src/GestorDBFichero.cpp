/*
 * GestorDBFichero.cpp
 *
 *  Created on: 18/12/2014
 *      Author: i22caboc
 */

#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>	//Necesario para atoi()
#include "Agenda.hpp"
#include "GestorDBFichero.hpp"

#define MAX 50

using namespace std;

bool GestorDBFichero::guardar(list<Contacto> aux) {
	if(aux.empty())
	return false;

	string nombreFichero;
	ofstream fichero;

	cout << "Introduzca el nombre del fichero donde se guardaran los contactos: "; 
	cin >> nombreFichero;

	//Abrimos el fichero para escribir
	fichero.open(nombreFichero.c_str(), ios::out);

	//Escribimos los contactos en el fichero
	for (list <Contacto>:: iterator iter = aux.begin(); iter != aux.end(); iter++) {
		fichero << iter->getNombre() << ","
		<< iter->getApellido1() << ","
		<< iter->getApellido2() << ","
		<< iter->getDNI() << ","
		<< iter->getEmail() << ",";

		//Lista de telefonos
		fichero << iter->getTelefono().size() << ",";	//indicamos el numero de elementos
		for (list <string>:: iterator itert = iter->getTelefono().begin(); itert != iter->getTelefono().end(); itert++)
			fichero << *itert << ",";

		//Lista de redes sociales
		fichero << iter->getRedSocial().size() << ",";
		for (list <redSocial>:: iterator iterr = iter->getRedSocial().begin(); iterr != iter->getRedSocial().end(); iterr++) {
			fichero << iterr->twitter << ","
			<< iterr->facebook << ","
			<< iterr->gPlus << ","
			<< iterr->url << ",";
		}

		//Lista de direcciones postales
		fichero << iter->getDireccionPostal().size() << ",";
		for (list <direccionPostal>:: iterator iterd = iter->getDireccionPostal().begin(); iterd!= iter->getDireccionPostal().end(); iterd++) {
			fichero << iterd->municipio << ","
			<< iterd->provincia << ","
			<< iterd->calle << ","
			<< iterd->portal << ","
			<< iterd->piso << ","
			<< iterd->puerta << ","
			<< iterd->codigoPostal << ",";
		}

		if(iter->esFavorito())
			fichero << 1 << ",";
		else
			fichero << 0 << ",";

		fichero << iter->numeroBusquedas() << "\n";
		//Fin de la linea
	}

	//Cerramos el fichero
	fichero.close();

  return true;
}



list<Contacto> GestorDBFichero::cargar(const string &fichero) {

	ifstream file(fichero.c_str());

	if(not file.is_open()) {
		cout << "El fichero no se ha podido abrir" << endl;
		getchar();
		getchar();
	}

	int cont = 0;
	Contacto contacto;	//Creamos un contacto "vacio"
	redSocial redes;
	list <string> telefonos;
	list<Contacto> contactos;
	direccionPostal direcciones;
	string telephono;

	char *num_tel = NULL, *num_red = NULL, *num_dir = NULL, *favorito = NULL;
	char nombre[MAX], apellido1[MAX], apellido2[MAX], DNI[MAX], email[MAX],
	telefono[MAX], busquedas[3], twitter[MAX], facebook[MAX], gplus[MAX], url[MAX],
	municipio[MAX], provincia[MAX], calle[MAX], portal[MAX], piso[MAX], puerta[MAX], codigo[MAX];


	while (file.getline(nombre,MAX,',')) {
		file.getline(apellido1, MAX, ',');
		file.getline(apellido2, MAX, ',');
		file.getline(DNI, MAX, ',');
		file.getline(email, MAX, ',');

		//Leemos los telefonos
		file.getline(num_tel, 1, ',');
		cont = atoi(num_tel);
		while(cont > 0) {
			file.getline(telefono, MAX, ',');
			telephono = string(telefono);
			telefonos.push_back(telefono);
		}

		file.getline(num_red, 1, ',');
		cont = atoi(num_red);
		for (int i = cont; i > 0; i--) {
			file.getline(twitter, MAX, ',');
			file.getline(facebook, MAX, ',');
			file.getline(gplus, MAX, ',');
			file.getline(url, MAX, ',');

			redes.twitter = string(twitter);
			redes.facebook = string(facebook);
			redes.gPlus = string(gplus);
			redes.url = string(url);

			contacto.addRedSocial(redes);
		}

		file.getline(num_dir, 1, ',');
		cont = atoi(num_dir);
		while (cont > 0) {
			file.getline(municipio, MAX, ',');
			file.getline(provincia, MAX, ',');
			file.getline(calle, MAX, ',');
			file.getline(portal, MAX, ',');
			file.getline(piso, MAX, ',');
			file.getline(puerta, MAX, ',');
			file.getline(codigo, MAX, ',');

			direcciones.municipio = string(municipio);
			direcciones.provincia = string(provincia);
			direcciones.calle = string(calle);
			direcciones.portal = string(portal);
			direcciones.piso = atoi(piso);
			direcciones.puerta = string(puerta);
			direcciones.codigoPostal = atoi(codigo);

			contacto.addDireccionPostal(direcciones);
		}

		file.getline(favorito, 1, ',');
		file.getline(busquedas, 3, '\n');


		//Ahora, a meterlo todo en el contcto wiiiiiii
		contacto.setNombre(string(nombre));
		contacto.setApellido1(string(apellido1));
		contacto.setApellido2(string(apellido2));
		contacto.setDNI(string(DNI));
		contacto.setEmail(string(email));
		contacto.addTelefono(telefonos);

		int intFavorito = atoi(favorito);

		if(intFavorito == '1')
			contacto.cambiaFavorito();
		
		contacto.setFrecuente(atoi(busquedas));

		//Insertamos el contacto en la agenda	
		contactos.push_back(contacto);

	} //Fin del while (crei que nunca terminaria)

	file.close();

	return contactos;
}

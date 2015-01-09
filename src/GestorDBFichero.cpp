/*
 * GestorDBFichero.cpp
 *
 *  Created on: 18/12/2014
 *      Author: i22caboc
 */

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <stdlib.h>	//Necesario para atoi()
#include "Agenda.hpp"
#include "GestorDBFichero.hpp"


#define MAX 50

using namespace std;

bool GestorDBFichero::guardar(list<Contacto> aux) {
	if(aux.empty())
	return false;

	list <Contacto>:: iterator iter;
	list <string>:: iterator itert;
	list <redSocial>:: iterator iterr;
	list <direccionPostal>:: iterator iterd;

	string nombreFichero;
	ofstream fichero;

	cout << "Introduzca el nombre del fichero donde se guardaran los contactos: "; 
	cin >> nombreFichero;

	//Abrimos el fichero para escribir
	fichero.open(nombreFichero.c_str(), ios::out);

	//Escribimos los contactos en el fichero
	for (iter = aux.begin(); iter != aux.end(); iter++) {
		fichero << iter->getNombre() << ","
		<< iter->getApellido1() << ","
		<< iter->getApellido2() << ","
		<< iter->getDNI() << ","
		<< iter->getEmail() << ",";

		//Lista de telefonos
		fichero << iter->getTelefono().size() << ",";	//indicamos el numero de elementos
		if (iter->getTelefono().size() == 1)
		{
			itert = iter->getTelefono().begin();
			fichero << *itert << ",";
		}
		else
		{
			for (itert = iter->getTelefono().begin(); itert != iter->getTelefono().end(); itert++)
				fichero << *itert << ",";
		}
		//cout << "Fin telefonos" << endl;

		//Lista de redes sociales
		fichero << iter->getRedSocial().size() << ",";
		if (iter->getRedSocial().size() == 0)
		{

		}
		else if (iter->getRedSocial().size() == 1)
		{
			iterr = iter->getRedSocial().begin();
			fichero << iterr->twitter << ","
			<< iterr->facebook << ","
			<< iterr->gPlus << ","
			<< iterr->url << ",";
		}
		/* REVISAR
		else
		{
			for (iterr = iter->getRedSocial().begin(); iterr != iter->getRedSocial().end(); iterr++) {
				fichero << iterr->twitter << ","
				<< iterr->facebook << ","
				<< iterr->gPlus << ","
				<< iterr->url << ",";
			}
		}
		*/
		//cout << "Fin redes sociales" << endl;

		//Lista de direcciones postales
		fichero << iter->getDireccionPostal().size() << ",";

		if (iter->getDireccionPostal().size() == 0)
		{

		}
		else if (iter->getDireccionPostal().size() == 1)
		{
			iterd = iter->getDireccionPostal().begin();
			fichero << iterd->municipio << ","
			<< iterd->provincia << ","
			<< iterd->calle << ","
			<< iterd->portal << ","
			<< iterd->piso << ","
			<< iterd->puerta << ","
			<< iterd->codigoPostal << ",";
		}
		/* REVISAR TAMBIEN !!
		else
		for (iterd = iter->getDireccionPostal().begin(); iterd!= iter->getDireccionPostal().end(); iterd++) {
			fichero << iterd->municipio << ","
			<< iterd->provincia << ","
			<< iterd->calle << ","
			<< iterd->portal << ","
			<< iterd->piso << ","
			<< iterd->puerta << ","
			<< iterd->codigoPostal << ",";
		}
		*/

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

	int cont;
	Contacto contacto;	//Creamos un contacto "vacio"
	redSocial redes;
	list <string> telefonos;
	list<Contacto> contactos;
	direccionPostal direcciones;
	string linea, linea2;

	string nombre, apellido1, apellido2, DNI, email, num_tel,
	telefono, num_red, twitter, facebook, gplus, url, num_dir, municipio, provincia, calle, portal, piso, puerta, codigo;
	string favorito, busquedas;

	while (getline(file, nombre, ',')) {
		getline(file, apellido1, ',');
		getline(file, apellido2, ',');
		getline(file, DNI, ',');
		getline(file, email, ',');

		//Leemos los telefonos
		getline(file, num_tel, ',');

		cont = atoi(num_dir.c_str());
		while(cont > 0) {
			getline(file, telefono, ',');
			telefonos.push_back(telefono);
			cont--;
		}

		//Leemos las redes sociales

		getline(file, num_red, ',');
		;
		cont = atoi(num_red.c_str());
		for (int i = cont; i > 0; i--) {
			getline(file, twitter, ',');
			getline(file, facebook, ',');
			getline(file, gplus, ',');
			getline(file, url, ',');;

			redes.twitter = string(twitter);
			redes.facebook = string(facebook);
			redes.gPlus = string(gplus);
			redes.url = string(url);

			contacto.addRedSocial(redes);
		}

		//Leemos las direcciones postales

		getline(file, num_dir, ',');

		cont = atoi(num_dir.c_str());
		while (cont > 0) {
			getline(file, municipio, ',');
			getline(file, provincia, ',');
			getline(file, calle, ',');
			getline(file, portal, ',');
			getline(file, piso, ',');
			getline(file, puerta, ',');
			getline(file, codigo, ',');

			direcciones.municipio = string(municipio);
			direcciones.provincia = string(provincia);
			direcciones.calle = string(calle);
			direcciones.portal = string(portal);
			direcciones.piso = string(piso);
			direcciones.puerta = string(puerta);
			direcciones.codigoPostal = string(codigo);

			contacto.addDireccionPostal(direcciones);
			cont--;
		}

		getline(file, favorito, ',');
		getline(file, num_dir, '\n');


		//Ahora, a meterlo todo en el contcto wiiiiiii
		contacto.setNombre(string(nombre));
		contacto.setApellido1(string(apellido1));
		contacto.setApellido2(string(apellido2));
		contacto.setDNI(string(DNI));
		contacto.setEmail(string(email));
		contacto.addTelefono(telefonos);

		int intFavorito;
		intFavorito = atoi(favorito.c_str());


		if(intFavorito == '1')
			contacto.cambiaFavorito();
		
		int busquedasC;
		busquedasC = atoi(busquedas.c_str());
		contacto.setFrecuente(busquedasC);

		//Insertamos el contacto en la agenda	
		contactos.push_back(contacto);

	} //Fin del while (crei que nunca terminaria)

	file.close();
	return contactos;
}

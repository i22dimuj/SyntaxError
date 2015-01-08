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

namespace agenda {

bool GestorDBFichero::guardar(list<Contacto> aux) {

  //Si la agenda esta vacia, no escribiremos nada en el fichero
	/*
  if(not a.getContactos())
		return false;
		CAMBIAR POR aux.empty();
		*/

  string fichero;
  ofstream flujoSalida;

	cout << "Introduzca el nombre del fichero donde se guardaran los contactos: "; 
	cin >> fichero;

	//Abrimos el fichero para escribir
	flujoSalida.open(fichero.c_str(), ios::out);

	//Escribimos los contactos en el fichero
	for (list <Contacto>:: iterator iter = aux.begin(); iter != aux.end(); iter++)
	{
		//Creo que estos serían iter y no aux
		flujoSalida << iter->getNombre() << ",";
		flujoSalida << iter->getApellido1() << ",";
		flujoSalida << iter->getApellido2() << ",";
		flujoSalida << iter->getDNI() << ",";
		flujoSalida << iter->getEmail() << ",";

#if 0 // ARREGLAR
		//Lista de telefonos
		flujoSalida << aux.getTelefono().size() << ",";	//indicamos el numero de elementos
		for (list <string>:: iterator itert = aux.getTelefono().begin(); itert != aux.getTelefono().end(); itert++)
			flujoSalida << *itert << ",";

		//Lista de redes sociales
		flujoSalida << aux.getRedSocial().size() << ",";
		for (list <redSocial>:: iterator iterr = aux.getRedSocial().begin(); iterr != aux.getRedSocial().end(); iterr++)
		{
			flujoSalida << iterr->twitter << ",";
			flujoSalida << iterr->facebook << ",";
			flujoSalida << iterr->gPlus << ",";
			flujoSalida << iterr->url << ",";
		}

		//Lista de direcciones postales
		int ultimo = 1;
		flujoSalida << aux.getDireccionPostal().size() << ",";
		for (list <direccionPostal>:: iterator iterd = aux.getDireccionPostal().begin(); iterd!=aux.getDireccionPostal().end();iterd++)
		{
			flujoSalida << iterd->municipio << ",";
			flujoSalida << iterd->provincia << ",";
			flujoSalida << iterd->calle << ",";
			flujoSalida << iterd->portal << ",";
			flujoSalida << iterd->piso << ",";
			flujoSalida << iterd->puerta << ",";
			flujoSalida << iterd->codigoPostal << ",";
		}

		if(aux.esFavorito())
			flujoSalida << 1 << ",";
		else
			flujoSalida << 0 << ",";

		flujoSalida << aux.numeroBusquedas() << "\n";
		//Fin de la linea
#endif
	}

	//Cerramos el fichero
	flujoSalida.close();

  return true;
}



list<Contacto> GestorDBFichero::cargar(const string &fichero) {

	/*Agenda a = new Agenda();*/
	list<Contacto> contactos;
#if 0

	char nombre[MAX], apellido1[MAX], apellido2[MAX], DNI[MAX], email[MAX], telefono[MAX],
	favorito, busquedas[3], twitter[MAX], facebook[MAX], gplus[MAX], url[MAX], municipio[MAX],
	provincia[MAX], calle[MAX], portal[MAX], piso[MAX], puerta[MAX], codigo[MAX];
	char num_tel, num_red, num_dir;


	int cont = 0;
	list <string> tel;
	redSocial r;
	direccionPostal dp;
	Contacto c;	//Creamos un contacto "vacio"

	//Abrimos fichero en modo lectura
	ifstream txt(fichero.c_str());

	while (txt.getline(nombre,MAX,','))
	{
		txt.getline(apellido1, MAX, ',');
		txt.getline(apellido2, MAX, ',');
		txt.getline(DNI, MAX, ',');
		txt.getline(email, MAX, ',');
		//Leemos los telefonos
		txt.getline(num_tel, 1, ',');
		cont = atoi(num_tel);
		while(cont > 0)
		{
			txt.getline(telefono, MAX, ',');
			tel.push_back(new string(telefono));
		}

		txt.getline(num_red, 1, ',');		
		cont = atoi(num_red);
		while(cont > 0)
		{
			txt.getline(twitter, MAX, ',');
			txt.getline(facebook, MAX, ',');
			txt.getline(gplus, MAX, ',');
			txt.getline(url, MAX, ',');

			r.twitter = new string(twitter);
			r.facebook = new string(facebook);
			r.gPlus = new string(gplus);
			r.url = new string(url);

			c.addRedSocial(r);
			cont--;
		}

		txt.getline(num_dir, 1, ',');		
		cont = atoi(num_dir);
		while (cont > 0)
		{
			txt.getline(municipio, MAX, ',');
			txt.getline(provincia, MAX, ',');
			txt.getline(calle, MAX, ',');
			txt.getline(portal, MAX, ',');
			txt.getline(piso, MAX, ',');
			txt.getline(puerta, MAX, ',');
			txt.getline(codigo, MAX, ',');

			dp.municipio = new string(municipio);
			dp.provincia = new string(provincia);
			dp.calle = new string(calle);
			dp.portal = new string(portal);
			dp.piso = atoi(piso);
			dp.puerta = new string(puerta);
			dp.codigoPostal = atoi(codigo);

			c.addDireccionPostal(dp);
		}

		txt.getline(favorito, 1, ',');
		txt.getline(busquedas, 3, '\n');


		//Ahora, a meterlo todo en el contcto wiiiiiii
		c.setNombre(new string(nombre));
		c.setApellido1(new string(apellido1));
		c.setApellido2(new string(apellido2));
		c.setDNI(new string(DNI));
		c.setEmail(new string(email));
		c.addTelefono(tel);

		if(favorito == '1')
			c.cambiaFavorito();
		
		c.setFrecuente(atoi(busquedas));

		//Insertamos el contacto en la agenda	
		contactos.push_back(c);

	} //Fin del while (crei que nunca terminaria)

	txt.close();
#endif


  return contactos;
}


} /* namespace agenda */

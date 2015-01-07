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
#include "GestorDBFichero.hpp"
#include "Funciones.hpp"

#define MAX 50

namespace std;
namespace agenda {


GestorDBFichero::bool guardar(const Agenda &a){

  string fichero;
  ofstream flujoSalida;
  list <Contacto> aux;
  list <Contacto>:: iterator iter;


	aux = a.getContactos();

		//Si la lista esta vacia, no escribiremos nada en el fichero
	if(aux.empty())
		return false;





	cout << "Introduzca el nombre del fichero donde se guardaran los contactos: "; 
	cin >> fichero;

		//Abrimos el fichero para escribir
	flujoSalida.open(fichero.c_str, ios::out);




		//Escribimos los contactos en el fichero

	for(iter = aux.begin(); iter != aux.end(); iter++){
	
		flujoSalida << aux.getNombre() << ",";
		flujoSalida << aux.getApellido1() << ",";
		flujoSalida << aux.getApellido2() << ",";
		flujoSalida << aux.getDNI() << ",";
		flujoSalida << aux.getEmail() << ",";

		//Lista de telefonos
		list <string>:: iterator itert;
		flujoSalida << aux.getTelefono().size() << ",";	//indicamos el numero de elementos
		for(itert = aux.getTelefono().begin(); itert != aux.getTelefono().end(); itert++)

			flujoSalida << *iter << ",";

		//Lista de redes sociales
		list <redSocial>:: iterator iterr;
		flujoSalida << aux.getRedSocial().size() << ",";
		for(iterr = aux.getRedSocial().begin(); iterr != aux.getRedSocial().end(); iterr++){

			flujoSalida << iter->twitter << ",";
			flujoSalida << iter->facebook << ",";
			flujoSalida << iter->gplus << ",";
			flujoSalida << iter->url << ",";
		}

		//Lista de direcciones postales
		list <direccionPostal>:: iterator iterd;
		int ultimo = 1;
		flujoSalida << aux.getDireccionPostal().size() << ",";
		for(iterr = aux.getDireccionPostal().begin(); iterr!=aux.getDireccionPostal().end();iterr++){

			flujoSalida << iter->municipio << ",";
			flujoSalida << iter->provincia << ",";
			flujoSalida << iter->calle << ",";
			flujoSalida << iter->portal << ",";
			flujoSalida << iter->piso << ",";
			flujoSalida << iter->puerta << ",";
			flujoSalida << iter->codigoPostal << ",";
		}

		if(aux.esFavorito)
			flujoSalida << 1 << ",";
		else
			flujoSalida << 0 << ",";

		flujoSalida << aux.numeroBusquedas() << "\n";
		//Fin de la linea
	}

	//Cerramos el fichero
	flujoSalida.close();

  return true;
}



GestorDBFichero::Agenda cargar(const string &fichero){

  Agenda a;

  char nombre[MAX], apellido1[MAX], apellido2[MAX], DNI[MAX], email[MAX], telefono[MAX],
  favorito, busquedas[3], twitter[MAX], facebook[MAX], gplus[MAX], url[MAX], municipio[MAX],
  provincia[MAX], calle[MAX], portal[MAX], piso[MAX], puerta[MAX], codigo[MAX];
  char num_tel, num_red, num_dir;

  int cont = 0;
  list <string> tel;
  redSocial r;
  direccionPostal dp;
  Contacto c("","","","","");	//Creamos un contacto "vacio"


	//Abrimos fichero en modo lectura
	ifstream txt(fichero.c_str);


	while(txt.getline(nombre,MAX,',')){

		txt.getline(apellido1, MAX, ',');
		txt.getline(apellido2, MAX, ',');
		txt.getline(DNI, MAX, ',');
		txt.getline(email, MAX, ',');
		
		//Leemos los telefonos
		txt.getline(num_tel, 1, ',');
		cont = atoi(num_tel);
		while(cont > 0){

			txt.getline(telefono, MAX, ',');
			tel.push_back(new string(telefono));
		}

		txt.getline(num_red, 1, ',');		
		cont = atoi(num_red);
		while(cont > 0){

			txt.getline(twitter, MAX, ',');
			txt.getline(facebook, MAX, ',');
			txt.getline(gplus, MAX, ',');
			txt.getline(url, MAX, ',');


			r.twitter = new string(twitter);
			r.facebook = new string(facebook);
			r.gplus = new string(gplus);
			r.url = new string(url);

			c.addRedSocial(r);
		}

		txt.getline(num_dir, 1, ',');		
		cont = atoi(num_dir);
		while(cont > 0){

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
		a.insertar(c);

	} //Fin del while (crei que nunca terminaria)

	txt.close();


  return a;
}


} /* namespace agenda */

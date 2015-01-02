/*
 * GestorDBFichero.cpp
 *
 *  Created on: 18/12/2014
 *      Author: i22caboc
 */


#include <iostream>
#include <fstream>
#include <list>
#include "GestorDBFichero.hpp"

namespace std;
namespace agenda {


GestorDBFichero::bool guardar(const Agenda &a){

  string fichero;
  ofstream flujoSalida;
  list <Contacto> aux;
  list <Contacto>:: iterator iter;

	cout << "Introduzca el nombre del fichero donde se guardaran los contactos: "; 
	cin >> fichero;

		//Abrimos el fichero para escribir
	flujoSalida.open(fichero.c_str, ios::out);

	aux = a.getContactos();

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
		flujoSalida << aux.getDireccionPostal().size() << ",";
		for(iterr = aux.getDireccionPostal().begin(); iterr!=aux.getDireccionPostal().end(); iterr++){

			flujoSalida << iter->municipio << ",";
			flujoSalida << iter->provincia << ",";
			flujoSalida << iter->calle << ",";
			flujoSalida << iter->portal << ",";
			flujoSalida << iter->piso << ",";
			flujoSalida << iter->puerta << ",";
			flujoSalida << iter->codigoPostal << ",";  //¿Importa poner una coma al final en 
		}						   //lugar de un \n?
	}
}



GestorDBFichero::Agenda cargar(const string &fichero){








}


} /* namespace agenda */

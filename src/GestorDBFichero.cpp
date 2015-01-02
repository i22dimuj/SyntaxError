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
	
		flujoSalida <<;




	}
}



GestorDBFichero::Agenda cargar(const string &fichero){








}


} /* namespace agenda */

#include <iostream>
#include "Contacto.hpp"

using namespace std;

namespace agenda {


Contacto::Contacto(){

  int dni, nombre, apellido1, apellido2, telefono;

	cout<<"\nIntroduce el nombre del nuevo Contacto: ";
	cin >> nombre;
	cout<<"Introduce el primer apellido del nuevo Contacto: ";
	cin >> apellido1;
	cout<<"Introduce el segundo apellido del nuevo Contacto: ";
	cin >> apellido2;
	cout<<"Introduce el DNI del nuevo Contacto: ";
	cin >> dni;
	cout<<"Introduce el telefono del nuevo Contacto: ";
	cin >> telefono;



	_dni = dni;
	_nombre = nombre;
	_apellido1 = apellido1;
	_apellido2 = apellido2;
	_telefono.push_back(telefono);
	_favorito = false;
	_frecuente = 0;

}

Contacto::Contacto(string dni, string nombre, string apellido1, string apellido2, string telefono){

	_dni = dni;
	_nombre = nombre;
	_apellido1 = apellido1;
	_apellido2 = apellido2;
	_telefono.push_back(telefono);
	_favorito = false;
	_frecuente = 0;
}

}
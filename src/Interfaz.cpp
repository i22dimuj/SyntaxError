#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "Interfaz.hpp"
#include "Agenda.hpp"

using namespace std;

namespace agenda {

int Interfaz::menuAgenda()
{
	int salir = 1, seleccion;

	system("cls");
	cout << "----- Agenda -----" << endl << endl;
	cout << "Menu:" << endl;
	cout << "1) Buscar contacto" << endl;
	cout << "2) Añadir contacto" << endl;
	cout << "3) Modificar contacto" << endl;
	cout << "4) Imprimir lista de contactos" << endl;
	cout << "5) Copia de seguridad" << endl;
	cout << "6) Borrar contacto" << endl;
	cout << "7) Contactos frecuentes" << endl;
	cout << "8) Contactos favoritos" << endl;
	cout << "0) Salir" << endl << endl;
	cout << "Seleccione una opción y pulse enter: ";

	cin >> seleccion;

	if (seleccion == 0)
		return 0; //Le indicamos al main que salga

	if ((seleccion < 0) || (seleccion > 8))
	{
		cout << "Seleccione una opcion valida (persione enter): " << endl;
		getchar();
	}
	else
		menuFuncion(seleccion);
	return 1; //Le indicamos  al main que no salga
}

bool Interfaz::menuFuncion(int opc)
{
	switch(opc)
	{
	case 1: //Buscar contacto
		string apellido;
		cout << "Introduzca el apellido de la persona que quiere buscar: ";
		cin << apellido;
		imprimeContacto(seleccionaContacto(Agenda::buscar(apellido)));
		break;

	case 2: //Añadir contacto
		Agenda::insertar(rellenaContacto());

		break;

	case 3: //Modificar contacto

		break;

	case 4: //Imprimir Agenda
		imprimirAgenda();
		break;

	case 5: //Copia de seguridad

		break;

	case 6: //Borrar contacto
		string DNI;
		cout << "Introduzca el DNI de la persona que quiere borrar: ";
		cin >> DNI;

		if (Agenda::borrar(DNI))
			cout << "Borrado efectuado con exito" << endl;
		else
			cout << "No se ha podido borrar el contacto. Quizas el DNI introducino no exista." << endl;

		cout << "Pulse enter para continuar" << endl;
		getchar();

		break;

	case 7: //Mostrar frecuentes
		verFrecuentes();
		break;

	case 8: //Mostrar favoritos
		verFavoritos();
		break;

	case 0: //Salir
		return false;
		break;

	default:
		cout << "Ha habido un problema en menuFunion" << cout;
	}
	return true;
}

Contacto Interfaz::seleccionaContacto(list <Contacto> listaContactos)
{
	list <Contacto>::iterator iter;
	int i = 0, seleccion;

	system("clear");

	for (iter = listaContactos.begin(); iter != listaContactos.end(); iter++)
	{
		cout << i << ") " << iter->getNombre() << " " << iter->getApellido1() << " " << iter->getApellido2() << endl;
		i++;
	}
	cout << endl << "Seleccione el contacto deseado: " << endl;
	cin >> seleccion;

	iter = listaContactos.begin();
	advance(iter, seleccion);

	return *iter;

}

void Interfaz::imprimeContacto(Contacto contacto)
{
	system("clear");
	cout << "Nombre: " << contacto.getNombre() << endl;
	cout << "Apellidos: " << contacto.getApellido1() << " " << contacto.getApellido2() << endl;
	cout << "DNI: " << contacto.getDNI() << endl;
	/*
	 * Imprimir resto de imformacion
	 */
}

Contacto Interfaz::rellenarContacto() {

	Contacto contacto = new Contacto;
	string dni, nombre, apellido1, apellido2, telefono;

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

	contacto.setDNI(dni);
	contacto.setNombre(nombre);
	contacto.setApellido1(apellido1);
	contacto.setApellido2(apellido2);
	contacto.addTelefono(telefono);

	return contacto;
}

void Interfaz::imprimirAgenda()
{
	list <Contacto> aux;
	list <Contacto>::iterator iter;

	aux = Agenda::getContactos;

	system("clear");

	for (iter = aux.begin(); iter != aux.end(); iter++)
	{
		imprimeContacto(*iter);
		cout << endl << "------------------------------------------------------" << endl << endl;
	}

}
void Interfaz::verFavoritos()
{

}
void Interfaz::verFrecuentes()
{

}

} //Namespace Agenda

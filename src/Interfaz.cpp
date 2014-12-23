#include <iostream>
#include <cstdlib>
#include <cstdio>
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

		break;

	case 2: //Añadir contacto

		break;

	case 3: //Modificar contacto

		break;

	case 4: //Imprimir Agenda
		imprimirAgenda();
		break;

	case 5: //Copia de seguridad

		break;

	case 6: //Borrar contacto

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

	return iter;

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

void Interfaz::imprimirAgenda()
{

}
void Interfaz::verFavoritos()
{

}
void Interfaz::verFrecuentes()
{

}

} //Namespace Agenda

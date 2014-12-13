#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Interfaz.hpp"
#include "Agenda.hpp"

using namespace std;

class InterfazAgenda
{
	int menu()
	{
		int salir = 0, seleccion;


		while (salir == 0)
		{
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
			if ((seleccion >= 0) || (seleccion < 5))
			{
				salir = 1;
			}
			else
			{
				cout << "Seleccione una opcion correcta (pulse cualquier tecla para continuar):";
				getchar();
			}

		}
		return seleccion;
	}
};


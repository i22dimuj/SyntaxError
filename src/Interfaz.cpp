#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Interfaz.hpp"

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
			cout << "Menu" << endl;
			/*
			 * menu
			 */

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


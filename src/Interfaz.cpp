#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "Interfaz.hpp"
//#include "Agenda.hpp"
//#include "Contacto.hpp"
#include "Estructuras.hpp"

using namespace std;
//Completamos el paso de la agenda desde el main ----> ¿Otra forma? //Similar a constructor de copia de Agenda

Interfaz::Interfaz(Agenda &a) {
	_agenda.setFichero(a.getFichero());
	_agenda.setGestorDB(a.getGestorDB());
	_agenda.setContactos(a.getContactos());
	_agenda.setFrecuentes(a.getFrecuentes());
}

void Interfaz::menuAgenda()
{
	int seleccion;

	do {
	system("clear");
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

	if (seleccion == 0) {
		cout << "ME ZARGO IO" << endl;
		return; //Le indicamos al main que salga

	} else if ((seleccion < 0) || (seleccion > 8)) {
		cout << "Seleccione una opcion valida (persione enter): " << endl;
		getchar();
	} else {
		menuFuncion(seleccion);
	}
	} while (true);
}

bool Interfaz::menuFuncion(int opc)
{
	string dni, apellido;
	Contacto aux, aux2;

	switch(opc) {
		case 1: //Buscar contacto
			cout << "Introduzca el apellido de la persona que quiere buscar: ";
			cin >> apellido;
			imprimeContacto(seleccionaContacto(_agenda.buscar(apellido)));
		break;

		case 2: //Añadir contacto
			aux = rellenarContacto();
			_agenda.insertar(aux);
			cout << "Contacto inserado correctamente." << endl;
			cout << "Pulse enter para continuar" << endl;
			getchar();
			getchar();
			break;

		case 3: //Modificar contacto
			cout << "Introduzca el apellido de la persona que quiere modificar: ";
			cin >> apellido;
			aux = seleccionaContacto(_agenda.buscar(apellido));
			cout << "--------------------------" << endl;
			aux2 = rellenarContacto();

			_agenda.modificar(aux, aux2);

			break;

		case 4: //Imprimir Agenda
			imprimirAgenda();
			cout << "Pulse enter para continuar" << endl;
			getchar();
			getchar();
			break;

		case 5: //Copia de seguridad

			break;

		case 6: //Borrar contacto
			cout << "Introduzca el DNI de la persona que quiere borrar: ";
			cin >> dni;

			if (_agenda.borrar(dni))
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
			break;
	}
	return true;
}

Contacto Interfaz::seleccionaContacto(list <Contacto> listaContactos)
{
	list <Contacto>::iterator iter;
	int i = 0, seleccion;

	system("clear");
	if (listaContactos.empty())
	{
		cout << "No se ha encontrado el Contacto en la agenda" << endl;
		exit(1);
	}

	else if (listaContactos.size() == 1)
	{
		iter = listaContactos.begin();
		return *iter;
	}

	else
	{
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


}

void Interfaz::imprimeContacto(Contacto contacto)
{
	cout << "Nombre: " << contacto.getNombre() << endl;
	cout << "Apellidos: " << contacto.getApellido1() << " " << contacto.getApellido2() << endl;
	cout << "DNI: " << contacto.getDNI() << endl;
	cout << "e-mail: " << contacto.getEmail() << endl;

	cout << "Telefono/s: " << endl;
	imprimeTelefono(contacto);
	imprimeRedSocial(contacto);
	imprimeDireccionPostal(contacto);

	
}

Contacto Interfaz::rellenarContacto() {

	Contacto contacto;
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

	aux = _agenda.getContactos();

	system("clear");

	for (iter = aux.begin(); iter != aux.end(); iter++)
	{
		imprimeContacto(*iter);
		cout << endl << "------------------------------------------------------" << endl << endl;
	}

}
void Interfaz::verFavoritos()
{
	list <Contacto> aux = _agenda.getContactos();
	system("clear");
	for (list <Contacto>::iterator iter = aux.begin(); iter != aux.end(); iter++) {
		if(iter->esFavorito())
			imprimeContacto(*iter);
	}
}

void Interfaz::verFrecuentes()
{

	list <Contacto> aux;
	list <Contacto>::iterator iter;

	

	system("clear");

	for (iter = aux.begin(); iter != aux.end(); iter++)
		imprimeContacto(*iter);

}


void Interfaz::imprimeDireccionPostal(Contacto contacto){
	list <direccionPostal> listaDir;
	list <direccionPostal>::iterator iter;

	listaDir = contacto.getDireccionPostal();
	if (listaDir.empty())
	{
		for (iter = listaDir.begin(); iter != listaDir.end(); iter++)
		{
			cout << "-----------------------------" << endl;
			cout << "Municipio: " << iter->municipio << endl;
			cout << "Provincia: " << iter->provincia << endl;
			cout << "Calle: " << iter->calle << endl;
			cout << "Portal: " << iter->portal << endl;
			cout << "Piso : " << iter->piso << endl;
			cout << "Puerta: " << iter->puerta << endl;
			cout << "Codigo Postal : " << iter->codigoPostal << endl;
			cout << "----------------------------" << endl;
		}
	}

}

void Interfaz::imprimeRedSocial(Contacto contacto){
	list <redSocial> listaRed;
	list <redSocial>::iterator iter;

	listaRed = contacto.getRedSocial();
	if (!listaRed.empty())
	{
		for (iter = listaRed.begin(); iter != listaRed.end(); iter++)
		{
			cout << "---------------------------" << endl;
			cout << "twitter: " << iter->twitter << endl;
			cout << "facebook: " << iter->facebook << endl;
			cout << "gPlus: " << iter->gPlus << endl;
			cout << "url: " << iter->url << endl;
			cout << "---------------------------" << endl;
		}
	}
}
void Interfaz::imprimeTelefono(Contacto contacto)
{
	list <string>::iterator iter;
	if(contacto.getTelefono().size() == 1)
	{
		iter = contacto.getTelefono().begin();
		cout << "   " << *iter << endl;
	}

	else
	{
		for(iter = contacto.getTelefono().begin(); iter != contacto.getTelefono().end(); iter++)
		{
			cout << "	" << *iter << endl;
		}
	}
}

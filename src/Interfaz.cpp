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
			system("clear");
			imprimeContacto(seleccionaContacto(_agenda.buscar(apellido)));
			cout << "Pulse enter para continuar" << endl;
			getchar();
			getchar();
		break;

		case 2: //Añadir contacto
			aux = rellenarContacto();
			_agenda.insertar(aux);
			cout << endl << "Contacto insertado correctamente." << endl;
			cout << "Pulse enter para continuar";
			getchar();
			getchar();
			break;

		case 3: //Modificar contacto
			cout << "Introduzca el apellido de la persona que quiere modificar: ";
			cin >> apellido;
			aux = seleccionaContacto(_agenda.buscar(apellido));

			//Si no se encuentra un contacto con ese apellido, volvemos al menu
			if(aux.getApellido1() == ""){

				cout << endl << "Pulse enter para continuar" << endl;
				getchar();
				getchar();
				break;
			}
			cout << "--------------------------" << endl;
			aux2 = rellenarContactoModificar();

			_agenda.modificar(aux, aux2);

			break;

		case 4: //Imprimir Agenda
			imprimirAgenda();
			cout << "Pulse enter para continuar" << endl;
			getchar();
			getchar();
			break;

		case 5: //Copia de seguridad
				_agenda.getGestorDB()->guardar(_agenda.getContactos());
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
		Contacto c;
		return c;
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
	//Si no se ha encontrado un contacto con el apellido buscado
	//El contacto estara vacio
	if(contacto.getApellido1() == "")
		return;

	cout << "Nombre: " << contacto.getNombre() << endl;
	cout << "Apellidos: " << contacto.getApellido1() << " " << contacto.getApellido2() << endl;
	cout << "DNI: " << contacto.getDNI() << endl;
	cout << "e-mail: " << contacto.getEmail() << endl;

	cout << "Telefono/s: ";
	imprimeTelefono(contacto);
	imprimeRedSocial(contacto);
	imprimeDireccionPostal(contacto);

	
}

Contacto Interfaz::rellenarContacto() {

	Contacto contacto;
	string dni, nombre, apellido1, apellido2, telefono;
	string confirmacion, confirmacion2;

	cout<<"\nIntroduce el nombre del nuevo Contacto: ";
	cin >> nombre;
	contacto.setNombre(nombre);

	cout<<"Introduce el primer apellido del nuevo Contacto: ";
	cin >> apellido1;
	contacto.setApellido1(apellido1);

	getchar();	//Sin el se salta el cin del segundo apellido
	cout<<"Introduce el segundo apellido del nuevo Contacto: ";
	cin >> apellido2;
	contacto.setApellido2(apellido2);

	cout<<"Introduce el DNI del nuevo Contacto: ";
	cin >> dni;
	contacto.setDNI(dni);

	cout<<"Introduce el telefono del nuevo Contacto: ";
	cin >> telefono;
	contacto.addTelefono(telefono);

	cout << "¿Introducir Direccion postal? (s/n): ";
	cin >> confirmacion;
	if (confirmacion == "s")
	{
		do {
			contacto.addDireccionPostal(addDireccionPostal());
			cout << "¿Añadir otra direccion postal? (s/n): ";
			cin >> confirmacion2;
		}while (confirmacion2 == "s");
	}

	cout << "¿Introducir Redes Sociales? (s/n): ";
	cin >> confirmacion;
	if (confirmacion == "s")
	{
		do {
			contacto.addRedSocial(addRedSocial());
			cout << "¿Añadir otra red Social? (s/n): ";
			cin >> confirmacion2;
		}while (confirmacion2 == "s");
	}

	return contacto;
}

Contacto Interfaz::rellenarContactoModificar() {

	Contacto contacto;
	string dni, nombre, apellido1, apellido2, telefono;
	getchar();

	cout<<"\nIntroduce el nombre del nuevo Contacto: ";
	getline(cin, nombre);
	cout<<"Introduce el primer apellido del nuevo Contacto: ";
	getline(cin, apellido1);
	cout<<"Introduce el segundo apellido del nuevo Contacto: ";
	getline(cin, apellido2);
	cout<<"Introduce el DNI del nuevo Contacto: ";
	getline(cin, dni);
	cout<<"Introduce el telefono del nuevo Contacto: ";
	getline(cin, telefono);

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

	aux = _agenda.getContactos();

	system("clear");

	for (list <Contacto>::iterator iter = aux.begin(); iter != aux.end(); iter++)
	{
		imprimeContacto(*iter);
		cout << endl << "<========================================================>" << endl << endl;
	}

}
void Interfaz::verFavoritos()
{
	list <Contacto> aux = _agenda.getContactos();
	system("clear");
	for (list <Contacto>::iterator iter = aux.begin(); iter != aux.end(); iter++)
		if(iter->esFavorito())
			imprimeContacto(*iter);
}

void Interfaz::verFrecuentes()
{
	list <Contacto> aux;
	list <Contacto>::iterator iter;

	system("clear");

	for (iter = aux.begin(); iter != aux.end(); iter++)
		imprimeContacto(*iter);
}

struct direccionPostal Interfaz::addDireccionPostal()
{
	struct direccionPostal direccion;
	getchar();

	cout << "Municipio: ";
	getline(cin, direccion.municipio);
	cout << "Provincia: ";
	getline(cin, direccion.provincia);
	cout << "Calle: ";
	getline(cin, direccion.calle);
	cout << "Portal: ";
	getline(cin, direccion.portal);
	cout << "Piso : ";
	getline(cin, direccion.piso);
	cout << "Puerta: ";
	getline(cin, direccion.puerta);
	cout << "Codigo Postal : ";
	getline(cin, direccion.codigoPostal);

	return direccion;
}
void Interfaz::imprimeDireccionPostal(Contacto contacto){
	list <direccionPostal> listaDir;
	list <direccionPostal>::iterator iter;

	listaDir = contacto.getDireccionPostal();
	if (!listaDir.empty())
	{
		for (iter = listaDir.begin(); iter != listaDir.end(); iter++)
		{
			cout << "---------------------------" << endl;
			cout << "Municipio: " << iter->municipio << endl;
			cout << "Provincia: " << iter->provincia << endl;
			cout << "Calle: " << iter->calle << endl;
			cout << "Portal: " << iter->portal << endl;
			cout << "Piso : " << iter->piso << endl;
			cout << "Puerta: " << iter->puerta << endl;
			cout << "Codigo Postal : " << iter->codigoPostal << endl;
		}
	}

}

struct redSocial Interfaz::addRedSocial()
{
	struct redSocial red;
	getchar();

	cout << "twitter: ";
	getline(cin, red.twitter);
	cout << "facebook: ";
	getline(cin, red.facebook);
	cout << "gPlus: ";
	getline(cin, red.gPlus);
	cout << "url: ";
	getline(cin, red.url);

	return red;
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
	if(contacto.getTelefono().size() == 1)
		cout << " " << *contacto.getTelefono().begin() << endl;
	else
		for(list <string>::iterator iter = contacto.getTelefono().begin(); iter != contacto.getTelefono().end(); iter++)
			cout << " " << *iter << endl;
}

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "Interfaz.hpp"
#include "Agenda.hpp"
#include "Contacto.hpp"
#include "Estructuras.hpp"

using namespace std;

namespace agenda {

Interfaz::Interfaz(Agenda &a){	//Coompletamos el paso de la agenda desde el main ----> ¿Otra forma?
				//Similar a constructor de copia de Agenda

	Agenda::_agenda.setFichero(a.getFichero());	//¿"Agenda::" se pone antes o despues del objeto?
	Agenda::_agenda.setGestorDB(a.getGestorDB());
	Agenda::_agenda.setContactos(a.getContactos());
	Agenda::_agenda.setFrecuentes(a.getFrecuentes());
}


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
		Agenda::insertar(rellenarContacto());

		break;

	case 3: //Modificar contacto
		string apellido;
		Contacto aux, aux2;

		cout << "Introduzca el apellido de la persona que quiere modificar: ";
		cin << apellido;
		aux = seleccionaContacto(Agenda::buscar(apellido));
		cout << "--------------------------" << endl;
		aux2 = rellenaContacto();

		Agenda::modificar(aux, aux2);

		break;

	case 4: //Imprimir Agenda
		imprimirAgenda();
		break;

	case 5: //Copia de seguridad

		break;

	case 6: //Borrar contacto
		string dni;
		cout << "Introduzca el DNI de la persona que quiere borrar: ";
		cin >> dni;

		if (Agenda::borrar(dni))
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
	//Iterador para telefonos
	list <string>::iterator itert;
	//Iterador para redes sociales
	list <redSocial>::iterator iterr;
	//Iterador para direcciones postales
	list <direccionPostal>::iterator iterd;

	system("clear");
	cout << "Nombre: " << contacto.getNombre() << endl;
	cout << "Apellidos: " << contacto.getApellido1() << " " << contacto.getApellido2() << endl;
	cout << "DNI: " << contacto.getDNI() << endl;
	cout << "e-mail: " << contacto.getEmail() << endl;

	cout << "Telefono/s: " << endl;
	for(itert = contacto.getTelefono().begin(); itert != contacto.getTelefono().end(); itert++)	
		cout << "	" << *itert << endl;

	for(iterr = contacto.getRedSocial().begin(); iterr != contacto.getRedSocial().end(); iterr++){	
		imprimeRedSocial(*iterr);
		cout << "-----------------" << endl;
	}
	
	for(iterd = contacto.getDireccionPostal().begin();iterd != contacto.getDireccionPostal().end();iterd++){
		cout << "Direccion Postal " << i << endl << endl;	
		imprimeDireccionPostal(*iterd);
		cout << "-----------------" << endl;
	}
	
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

	aux = _agenda.Agenda::getContactos();

	system("clear");

	for (iter = aux.begin(); iter != aux.end(); iter++)
	{
		imprimeContacto(*iter);
		cout << endl << "------------------------------------------------------" << endl << endl;
	}

}
void Interfaz::verFavoritos()
{

	list <Contacto> aux;
	list <Contacto>::iterator iter;

	aux = _agenda.Agenda::getContactos();
	

	system("clear");

	for (iter = aux.begin(); iter != aux.end(); iter++)
	{
		if(iter->esFavorito()){

			imprimeContacto(*iter);
		}
		
	}



}
void Interfaz::verFrecuentes()
{

	list <Contacto> aux;
	list <Contacto>::iterator iter;

	aux = _agenda.Agenda::getFrecuentes();
	

	system("clear");

	for (iter = aux.begin(); iter != aux.end(); iter++)
		imprimeContacto(*iter);

}


void Interfaz::imprimeDireccionPostal(Contacto contacto){
	list <direccionPostal> listaDir;
	list <direccionPostal>::iterator iter;

	listaDir = contacto.getDireccionPostal();

	cout << "Municipio: " << iter->municipio << endl;
	cout << "Provincia: " << iter->provincia << endl;
	cout << "Calle: " << iter->calle << endl;
	cout << "Portal: " << iter->portal << endl;
	cout << "Piso : " << iter->piso << endl;
	cout << "Puerta: " << iter->puerta << endl;
	cout << "Codigo Postal : " << iter->codigoPostal << endl;

}

void Interfaz::imprimeRedSocial(Contacto contacto){
	list <redSocial> listaRed;
	list <redSocial>::iterator iter;

	listaRed = contacto.getRedSocial();

	for (iter = listaRed.begin(); iter != listaRed.end(); iter++)
	{
		cout << "twitter: " << iter->twitter << endl;
		cout << "facebook: " << iter->facebook << endl;
		cout << "gPlus: " << iter->gPlus << endl;
		cout << "url: " << iter->url << endl;
	}
}

} //Namespace Agenda

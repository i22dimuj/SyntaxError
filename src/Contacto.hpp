#ifndef CONTACTO_HPP
#define CONTACTO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contacto{


  private:

	string _nombre;
	string _apellido1;
	string _apellido2;
	string _DNI;
	string _email;
	vector <string> _telefono;
//	vector <RedSocial> _redSocial;
//	vector <DireccionPostal> _direccionPostal;

	bool _favorito;
	int _busquedas;

  public:

		//Constructores
	Persona(string DNI, string nombre, string apellido1, string apellido2, string telefono){

		_DNI = DNI;
		_nombre = nombre; 
		_apellido1 = apellido1;
		_apellido2 = apellido2;
		_telefono.push_back(telefono);
	

	Persona(){rellenarPersona();};



		//Observadores
	string getNombre(){return _nombre;};
	string getApellido1(){return _apellido1;};
	string getApellido2(){return _apellido2;};
	string getDNI(){return _DNI;};
	string getEmail(){return _email;};
	vector <string> getTelefono(){return _telefono;};		//Ni zorra de como se hacian estos dos gets que tienen que devolver el vector entero
	vector <RedSocial> getRedSocial(){return _redSocial;};
	vector <DireccionPostal> getDireccionPostal(){return _direccionPostal;};
	bool esFavorito(){return _favorito;};
	int numeroBusquedas(){return _busquedas;};

		//Modificadores
	void setNombre(string nombre){_nombre = nombre;};
	void setApellido1(string apellido){_apellido1 = apellido;};
	void setApellido2(string apellido){_apellido2 = apellido;};
	void setDNI(string DNI){_DNI = DNI;};
	void setEmail(string email){_email = email};
	void nuevoTelefono(string telefono){_telefono.push_back(telefono);};
	void nuevaDireccionPostal(DireccionPostal direccion){_direccionPostal.push_back(direccion);};
	void nuevaRedSocial(RedSocial red){_redSocial.push_back(red);};
	void busqueda++(){_busquedas++;};
	
	void cambiaFavorito(){

		if(_favorito == FALSE)
			_favorito = TRUE;

		else
			_favorito = FALSE;
	}











};
#endif

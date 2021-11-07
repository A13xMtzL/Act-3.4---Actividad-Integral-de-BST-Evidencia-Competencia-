#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //Libreria para pasar de cadena a numero	


using namespace std;

class CDirecciones_IP {
public:
	CDirecciones_IP(vector<string> datos);
	CDirecciones_IP() {}

	/*Definiremos variables de tipo string donde podamos guardar los elementos
	que se estan separando*/
	string ip;

	/*Al tratarse de cadenas de texto, debemos de definir funciones con
	las que podamos convertirlas a numeros  */

	int return_IP_numerica(string elemento);
};





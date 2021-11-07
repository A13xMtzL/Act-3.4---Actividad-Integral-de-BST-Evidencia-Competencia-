#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Emplearemos la funcion tokenize para poder separar los elementos del archivo
class CTokenize {
public:
	CTokenize();

	~CTokenize();

	void tokenizar(string const& str, const char delim, vector<string>& out); //Complejidad: O(n)


private:

};




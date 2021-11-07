//#pragma once
#include "COrdenamineto_QuickSort.h"
using namespace std;

COrdenamineto_QuickSort::COrdenamineto_QuickSort() {
	primero = 0;
	ultimo = 0;
	pivote = 0;
}

COrdenamineto_QuickSort::~COrdenamineto_QuickSort() {} //Complejidad: O(log n) 

/*Decidimos usar la funcion de ordenamiento QuickSort puesto que es la mas optima y esta podria
   reducir los tiempos de ejecucion del codigo */
void COrdenamineto_QuickSort::Ordenamiento_QuickSort(vector<int>& A, vector<string>& B, int _primero, int _ultimo) {
	//Quicksort necesita usar el primer y el ultimo elemento de la lista (primero,ultimo)
	//Al igual que necesita del elemento central de la lista (pivote) 
	int pivote, primero, ultimo;
	pivote = A[(_primero + _ultimo) / 2];

	//Declaramos el primer y ultimo elemento de la lista 
	primero = _primero;
	ultimo = _ultimo;
	
	//Se deben seprarar en dos los elementos del arreglo, seprando valores menores al pivote 
	//y valores mayores al pivote 
	
	do {
		while (A[primero] < pivote) primero++; //Elementos mayores al pivote 
		while (A[ultimo] > pivote) ultimo--; //Elementos menores al pivote

		//Haremos uno de variables auxiliares para poder cambiar los valores, en caso de que esten desordenados 
		if (primero <= ultimo) {   

			int auxiliar_1;

			auxiliar_1 = A[primero];
			A[primero] = A[ultimo];
			A[ultimo] = auxiliar_1;

			string auxiliar_2;

			auxiliar_2 = B[primero];
			B[primero] = B[ultimo];
			B[ultimo] = auxiliar_2;

			primero++;	//Aumentamos el valor del primer elemento
			ultimo--;	//Disminuimos el valor del ultimo elemento
		}
	} while (primero <= ultimo);
	//Se aplica recursividad para seguir ordenando los elementos 
  if (_primero < ultimo)
		Ordenamiento_QuickSort(A, B, _primero, ultimo);
	if (primero < _ultimo)
		Ordenamiento_QuickSort(A, B, primero, _ultimo);
}
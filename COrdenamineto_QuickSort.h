#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class COrdenamineto_QuickSort {

public:
	int pivote, primero, ultimo;
	COrdenamineto_QuickSort();

	~COrdenamineto_QuickSort();

	void Ordenamiento_QuickSort(vector<int>& A, vector<string>& B, int primero, int ultimo); //Complejidad: O(log n) 
};


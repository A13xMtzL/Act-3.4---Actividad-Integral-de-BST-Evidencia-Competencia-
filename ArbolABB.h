#pragma once
#include<iostream>

class ArbolABB {
private:
    //// Se crea de forma local la clase Nodo, misma que se va para el manejo del arbol binario
    class Nodo {
    public:
        // Contructor de la clase Nodo
        Nodo(const int dat, Nodo* izq = NULL, Nodo* der = NULL) :
            dato(dat), izquierdo(izq), derecho(der) {}
        // Variables de la clase Nodo
        int dato;
        Nodo* izquierdo;
        Nodo* derecho;
    };

    // Se definen los punteros, uno destinado al nodo raiz del arbol y el otro al nodo actual
    Nodo* raiz;
    Nodo* actual;


    int contador;  //Se crea una variable contadora  
    int altura;

public:
    // Constructor y destructor basico de la clase
    ArbolABB() : raiz(NULL), actual(NULL) {}
    ~ArbolABB() { Podar(raiz); }
    // Funcion para insertar un elemento del arbol 
    void Insertar(const int dat);
    // Funcion para borrar un elemento del arbol
    void Borrar(const int dat);
    // Funcion para buscar un elemento en el arbol
    bool Buscar(const int dat);
    // Esta funcion nos ayuda a comprobar si el arbol se encuentra vacio
    bool Vacio(Nodo* r) { return r == NULL; }
    // Esta funcion nos ayuda a comprobar si el nodo en el que estamos es un nodo hoja
    bool EsHoja(Nodo* r) { return !r->derecho && !r->izquierdo; }
    // Funcion que nos ayudara a contar el numero de nodos 
    const int NumeroNodos();
    const int AlturaArbol();
    // Funcion que nos calcula la altura de un arbol
    int Altura(const int dat);
    // 
    int& ValorActual() { return actual->dato; }
    // Funcion que nos manda al nodo raiz
    void Raiz() { actual = raiz; }
    // Funciones de recorrido de un Arbol Binario
    void InOrden(void (*func)(int&), Nodo* nodo = NULL, bool r = true);
    void PreOrden(void (*func)(int&), Nodo* nodo = NULL, bool r = true);
    void PostOrden(void (*func)(int&), Nodo* nodo = NULL, bool r = true);
private:
    // Funciones auxiliares 
    void Podar(Nodo*&);
    void auxContador(Nodo*);
    void auxAltura(Nodo*, int);
};
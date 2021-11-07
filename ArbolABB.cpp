#include "ArbolABB.h"
#include <vector>

// Funcion Podar, encargada de eliminar una cantidad de nodos, incluido el nodo padre
void ArbolABB::Podar(Nodo*& nodo)
{
    // Se realiza un recorrido en postorden(por ello empezamos con el nodo izquierdo, seguido del derecho y por ultimo el padre)
    if (nodo) {
        Podar(nodo->izquierdo); // Se poda el nodo izquierdo
        Podar(nodo->derecho);   // Se poda el nodo derecho
        delete nodo;            // Se poda el nodo padre
        nodo = NULL;
    }
}

// Funcion Insertar, inserta un valor entero en el Arbol 
void ArbolABB::Insertar(const int dat)
{
    Nodo* padre = NULL;

    actual = raiz;
    // Si el arbol se encuentra vacio o no se encuentra un nodo raiz, se crea una raiz 
    while (!Vacio(actual) && dat != actual->dato) {
        padre = actual;
        if (dat > actual->dato) actual = actual->derecho;
        else if (dat < actual->dato) actual = actual->izquierdo;
    }

    // En caso de que se haya encontrado el elemento, se regresara el mismo
    if (!Vacio(actual)) return;
    // Comprobamos si el nodo padre tiene informacion, en caso contrario asignamos un nuevo nodo con el dato que nos han pasado como parametro
    if (Vacio(padre)) raiz = new Nodo(dat);
    // verifica que dato sea menor que el padre y lo coloca en la rama izquierda 
    else if (dat < padre->dato) padre->izquierdo = new Nodo(dat);
    // verifica que dato sea menor que el padre y lo coloca en la rama derecha 
    else if (dat > padre->dato) padre->derecho = new Nodo(dat);
}

// Funcion para eliminar un elemento de un Arbol
void ArbolABB::Borrar(const int dat)
{
    Nodo* padre = NULL;
    Nodo* nodo;
    int aux;

    actual = raiz;
    // Se recorre todo el arbol simepre y cuando el valor se encuentre en el arbol
    while (!Vacio(actual)) {
        if (dat == actual->dato) { // Verificamos si el valor a eliminar esta en el nodo actual
            if (EsHoja(actual)) { // Verificamos si el valor a eliminar es un nodo hoja
                if (padre) // Verificamos si el nodo tiene padre 
                   // En este caso anulamos el apuntador al que se le hace refrencia 
                    if (padre->derecho == actual) padre->derecho = NULL;
                    else if (padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // Borramos el nodo
                actual = NULL;
                return;
            }
            else { // En caso de que el valor a eliminar no sea un nodo hoja
               // Buscaremos el nodo con el valor a eliminar 
                padre = actual;
                // Se busca el nodo que se encuentre mas a la izquierda de la rama derecha 
                if (actual->derecho) {
                    nodo = actual->derecho;
                    while (nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                // En un caso contrario bucamos el nodo que se encuentre mas a la derecha de la rama izquierda
                else {
                    nodo = actual->izquierdo;
                    while (nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                // Se intercambian valores 
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
        }
        else { // En caso de que no encontremos el valor a eliminar, se sigue buscando
            padre = actual;
            if (dat > actual->dato) actual = actual->derecho;
            else if (dat < actual->dato) actual = actual->izquierdo;
        }
    }
}

// Recorrido de arbol en inorden
// void (*func)(int&)
void ArbolABB::InOrden(void (*func)(int&), Nodo* nodo, bool r)
{
    if (r) nodo = raiz;
    if (nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
    func(nodo->dato);
    if (nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de arbol en preorden
// void (*func)(int&)
void ArbolABB::PreOrden(void (*func)(int&), Nodo* nodo, bool r)
{
    if (r) nodo = raiz;
    func(nodo->dato);
    if (nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if (nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de arbol en postorden
// void (*func)(int&)
void ArbolABB::PostOrden(void (*func)(int&), Nodo* nodo, bool r)
{
    if (r) nodo = raiz;
    if (nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
    if (nodo->derecho) PostOrden(func, nodo->derecho, false);
    func(nodo->dato);
}

// Se busca un valor en el arbol
bool ArbolABB::Buscar(const int dat)
{
    actual = raiz;

    // Se recorrera todo el arbol, siempre y cuando el valor actual no se encuntre vacio
    while (!Vacio(actual)) {
        if (dat == actual->dato) return true; // Se retorna un true si el valor de dat es igual al valor del dato actual
        else if (dat > actual->dato) actual = actual->derecho; // 
        else if (dat < actual->dato) actual = actual->izquierdo;
    }
    return false; // Si el valor no esta en el arbol se regresa un falso 
}

// Funcion para calcular la altura del nodo que contiene el valor del dato
int ArbolABB::Altura(const int dat)
{
    int altura = 0;
    actual = raiz;

    // Se hace un ciclo para buscar el valor en los nodos del arbol
    while (!Vacio(actual)) {
        if (dat == actual->dato) return altura; // Verifica que el dato sea igual al valor del actual y regresa la altura 
        else {
            altura++; // Incrementa el valor de la altura
            if (dat > actual->dato) actual = actual->derecho;
            else if (dat < actual->dato) actual = actual->izquierdo;
        }
    }
    return -1; // Hace un return cuando no se encuentra en el arbol 
}

// Funcion para contar el numero de nodos
const int ArbolABB::NumeroNodos()
{
    contador = 0;

    auxContador(raiz); // Aumentamos el contador auxiliar del numero de Nodos
    return contador;
}

// Funcion es auxiliar y funciona para contar lo nodos
//Es una funcion recursiva (preorden)
void ArbolABB::auxContador(Nodo* nodo)
{
    contador++;  // Aumentar el contador, es otro nodo 
    //Recorrido en preorden 
    if (nodo->izquierdo) auxContador(nodo->izquierdo);
    if (nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del arbol
const int ArbolABB::AlturaArbol()
// La altura es el nodo con mayor altura
{
    altura = 0;

    auxAltura(raiz, 0); // Se utiliza la funcion auxiliar de altura 
    return altura;
}

// Funcion auxiliar para calcular la altura del arbol 
// Es recursiva (postorden)
void ArbolABB::auxAltura(Nodo* nodo, int a)
{
    // Recorrido en postorden 
    if (nodo->izquierdo) auxAltura(nodo->izquierdo, a + 1);
    if (nodo->derecho)   auxAltura(nodo->derecho, a + 1);
    // Se actuliza la altura del arbol 
    // Si es un nodo hoja y la altura de este es mayor a la del arbol
    if (EsHoja(nodo) && a > altura) altura = a;
}


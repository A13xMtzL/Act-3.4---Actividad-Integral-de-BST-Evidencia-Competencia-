#include "CArbol_BST.h"
using namespace std;


CArbol_BST::CArbol_BST() { //Complejidad:  O(1)
    this->size = 0;
    this->raiz = NULL;
}

//Función que busca nodos en el BST, recibe como parámetros un entero y un nodo apuntado, retorna un valor boolenao

bool CArbol_BST::buscar(int dato, Nodo_ABB *actual) { //Complejidad:  O(n)
  if (actual == NULL) {
    return false;
  } else if (actual->dato == dato) {
    return true;
  }
  if (dato < actual->dato) {
    return buscar(dato, actual->left);
  } else {
    return buscar(dato, actual->right);
  }
}

//Función que inserta nodos en el BST, recibe como parámetros un entero y un string constante referenciado, retorna un valor boolenao

bool CArbol_BST::Insertar(int key, const string &ip) { // Complejidad: O(n)
    if (this->raiz == NULL) {
        this->raiz = new Nodo_ABB(key, ip);
        size++;
        return true;
    } else {
        Nodo_ABB *actual = this->raiz, *previo= NULL;

        while (actual != NULL) {
            previo = actual;
            if (key == actual->dato) {
                return false;
            } else {
                actual = key < actual->dato ? actual->left : actual->right;
            }
        }

        if (key < previo->dato) {
            previo->left = new Nodo_ABB(key, ip);
        } else {
            previo->right = new Nodo_ABB(key, ip);
        }

        this->size++;
        return true;
    }
}

//Función que encuentra el valor minimo en el BST, recibe como parámetro un nodo apuntado y retorna un nodo apuntado

Nodo_ABB *CArbol_BST::min_Valor_Nodo(Nodo_ABB *nodo) { //Complejidad:  O(n)
    Nodo_ABB *actual = nodo;
    while (actual && actual->left != NULL)
        actual = actual->left;
    return actual;
}

//Función que elimina un nodo en el BST, recibe como parámetros un nodo apuntado, un entero y un valor booleano referenciado y retorna un nodo apuntado

Nodo_ABB *CArbol_BST::podar(Nodo_ABB *nodo, int dato, bool &success) { //Complejidad:  O(n)
    if (nodo == NULL) {
        success = false;
        return nodo;
    }
    if (dato < nodo->dato) {
        nodo->left = podar(nodo->left, dato, success);
    } else if (dato > nodo->dato) {
        nodo->right = podar(nodo->right, dato, success);
    } else {
        if (nodo->left == NULL) {
            Nodo_ABB *temp = nodo->right;
            delete nodo;
            success = true;
            return temp;
        } else if (nodo->right == NULL) {
            Nodo_ABB *temp = nodo->left;
            delete nodo;
            success = true;
            return temp;
        }
        Nodo_ABB *temp = min_Valor_Nodo(nodo->right);
        nodo->dato = temp->dato;
        raiz->right = podar(nodo->right, temp->dato, success);
    }

    return nodo;
}

//Función que imprime el BST en postorder, recibe como parámetro un nodo apuntado y no tiene valor de retorno.

void CArbol_BST::postorden(Nodo_ABB *actual) { //Complejidad:  O(n)
    if (actual != NULL) {
        postorden(actual->left);
        postorden(actual->right);
        cout << actual->dato << ",";
    }
}

//Función que imprime el BST en preorder, recibe como parámetro un nodo apuntado y no tiene valor de retorno.

void CArbol_BST::preorden(Nodo_ABB *actual) { //Complejidad:  O(n)
    if (actual != NULL) {
        cout << actual->dato << ",";
        this->preorden(actual->left);
        this->preorden(actual->right);
    }
}

//Función que imprime el BST en In_Orden_Inverso, , recibe como parámetro un nodo apuntado y no tiene valor de retorno.

void CArbol_BST::In_Orden_Inverso(Nodo_ABB *actual, int &count) { //Complejidad:  O(n)
    if (count > 0 || count == -1) {
        if (count != -1) {
            count--;
        }
        if (actual != NULL) {
            In_Orden_Inverso(actual->right, count);
            if (actual->dato!=0)
                cout<<"IP: "<< actual->ip << " --- Repeticiones: "<< actual->dato << endl;
            In_Orden_Inverso(actual->left, count);
        }
    }
}

//Funcion que implementa el In_Orden_Inverso, no recibe parámetros y no tiene valor de retorno.

void CArbol_BST::In_Orden_Inverso() { //Complejidad:  O(n)
    int count = -1;
    In_Orden_Inverso(this->raiz, count);
}

//Función que retorna la altura del BST, no recibe parámetros y no tiene valor de retorno.

int CArbol_BST::altura(Nodo_ABB *nodo) { //Complejidad:  O(n)
    if (nodo == NULL) {
        return 0;
    } else {
        int leftHeight = altura(nodo->left);
        int rightHeight = altura(nodo->left);

        if (leftHeight < rightHeight) {
            return (rightHeight + 1);
        } else {
            return (leftHeight + 1);
        }

    }
}

//Función que corrobora ancestros, recibe como parámetro un nodo apuntado, un entero y un string referenciado, retorna un valor booleano.

bool CArbol_BST::ancestros(Nodo_ABB *nodo, int dato, string &output) { //Complejidad:  O(n)
    if (nodo == NULL) {
        return false;
    }
    if (nodo->dato == dato) {
        return true;
    }
    if (ancestros(nodo->left, dato, output) || ancestros(nodo->right, dato, output)) {
        output.insert(0, to_string(nodo->dato) + ",");
        return true;
    } else {
        return false;
    }
}

//Función que retorna el nivel de un nodo dado, recibe como parámetro un nodo apuntado y dos enteros, retorna un valor entero.

int CArbol_BST::Nivel_Actual(Nodo_ABB *nodo, int dato, int level) { //Complejidad:  O(n)
    if (nodo == NULL) {
        return -1;
    }
    if (nodo->dato == dato) {
        return level;
    }
    int nextLevel = Nivel_Actual(nodo->left, dato, level + 1);
    if (nextLevel != 0) {
        return nextLevel;
    }
    nextLevel = Nivel_Actual(nodo->right, dato, level + 1);
    return nextLevel;
}

//Función que implementa el despliegue el Top 5 de IPs mas repetidas, no recibe parámetros y no tiene valor de retorna.

void CArbol_BST::Primeros_Cinco() { //Complejidad:  O(n)
    int count = -1;
    InOrden_Inverso_Primeros_Cinco(this->raiz, count);
    top=0;
}

//Función que despliega el reverseInorder del Top 5 IPs mas repetidas, recibe como parámetro un nodo apuntado y un entero referenciado, no tiene valor de retorno.

void CArbol_BST::InOrden_Inverso_Primeros_Cinco(Nodo_ABB *actual, int &count) { //Complejidad:  O(n)
    if (count > 0 || count == -1) {
        if (count != -1) {
            count--;
        }
        if (actual != NULL) {
            InOrden_Inverso_Primeros_Cinco(actual->right, count);
            if (top<5 && actual->dato!=0){
                cout<<"IP: "<< actual->ip << " --- Repeticiones: "<< actual->dato << endl;
                top++;
            }
            InOrden_Inverso_Primeros_Cinco(actual->left, count);
        }
    }
}
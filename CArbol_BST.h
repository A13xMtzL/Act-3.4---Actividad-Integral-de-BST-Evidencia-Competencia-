#include <iostream>
#include <fstream>


using namespace std;

//Definición de Estructura del BST para IPs
struct Nodo_ABB {
    int dato;
    string ip;
    Nodo_ABB *left, *right;
    explicit Nodo_ABB(int dato, string ip) {
        this->dato = dato;
        this->ip = move(ip);
        this->left = this->right = NULL;
    }
};

class CArbol_BST {
private:
  // Atributo con funcionalidad hacia el Top de IPs más buscadas
  int top = 0;
  
  // Número de elementos en el BST
  int size;

  // Apuntador a la raíz del BST
  Nodo_ABB *raiz;

  //Función que busca nodos en el BST, recibe como parámetros un entero y un nodo apuntado, retorna un valor boolenao.
  bool buscar(int dato, Nodo_ABB *actual); //Complejidad: O(n)

  //Función que elimina un nodo en el BST, recibe como parámetros un nodo apuntado, un entero y un valor booleano referenciado y retorna un nodo apuntado
  Nodo_ABB *podar(Nodo_ABB *nodo, int dato, bool &success); //Complejidad: O(n)

  //Función que imprime el BST en postorder, recibe como parámetro un nodo apuntado y no tiene valor de retorno.
  void postorden(Nodo_ABB *actual); //Complejidad: O(n)

  //Función que imprime el BST en preorder, recibe como parámetro un nodo apuntado y no tiene valor de retorno.
  void preorden(Nodo_ABB *actual); //Complejidad: O(n)

  //Función que imprime el BST en In_Orden_Inverso, , recibe como parámetro un nodo apuntado y no tiene valor de retorno.
  void In_Orden_Inverso(Nodo_ABB *actual, int &count); //Complejidad: O(n)

  //Función que despliega el In_Orden_Inverso del Top 5 IPs mas repetidas, recibe como parámetro un nodo apuntado y un entero referenciado, no tiene valor de retorno.
  void InOrden_Inverso_Primeros_Cinco(Nodo_ABB *actual, int &count); //Complejidad: O(n)

  //Función que encuentra el valor minimo en el BST, recibe como parámetro un nodo apuntado y retorna un nodo apuntado.
  static Nodo_ABB *min_Valor_Nodo(Nodo_ABB *nodo); //Complejidad: O(n)

  //Función que retorna la altura del BST, no recibe parámetros y no tiene valor de retorno.
  int altura(Nodo_ABB *nodo); //Complejidad: O(n)

  //Función que retorna el nivel de un nodo dado, recibe como parámetro un nodo apuntado y dos enteros, retorna un valor entero.
  int Nivel_Actual(Nodo_ABB *nodo, int dato, int level); //Complejidad: O(n)

public:
  //Constructor de la clase BST, establece el peso en cero y la raíz como apuntador nulo.
  CArbol_BST(); //Complejidad: O(1)

  //Función que Insertara nodos en el BST, recibe como parámetros un entero y un string constante referenciado, retorna un valor boolenao
  bool Insertar(int key, const string &ip); // Complejidad:  O(n)

  // Este método imprime In_Orden_Inverso del BST.
  // Complejidad:  O(n)
  void In_Orden_Inverso(); //Complejidad: O(n)

  //Función que implementa el despliegue el Top 5 de IPs mas repetidas, no recibe parámetros y no tiene valor de retorna.
  void Primeros_Cinco(); //Complejidad: O(n)

};


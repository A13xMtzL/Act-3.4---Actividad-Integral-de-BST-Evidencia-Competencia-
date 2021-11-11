//Codigo trabajado por: Alejandro Martinez Luna        -  A01276785
//                      Monserrat Karime Moreno Casas  -  A01276775

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include"CTokenize.h"
#include"COrdenamineto_QuickSort.h"
#include "CDirecciones_IP.h"

//Se incluyen las librerias de los arboles 
#include "CArbol_BST.h"


using namespace std;

// Funcion que muestra los valores del arbol separados por comas
void Mostrar(int& d){
	cout << d << ",";
}

//  Funcion donde se realiza la comprobacion de direcciones repetidas 
void comprueba_repetidos(  vector<string> vector ,CArbol_BST Arbolito_BST){ //  Complejidad: O(n)
  int contador = 1;
  cout<<endl;
  
  //Ciclo que despliega todas las direcciones, junto con su numero de repetidos
  for (int k = 1; k < vector.size()+1; k++) {
    //Compara la direccion actual con la anterior
    if (vector[k-1] == vector[k]){
      contador ++; //si son iguales se suma al contador
    }
    //Insertar la cantidad de repeticiones y la IP al árbol 
    else { 
      Arbolito_BST.Insertar(contador, vector[k-1]); 
      //if (contador>=2){
        cout << "Contador: " << contador << " direcciones: " << vector[k-1] << endl;
        contador = 1;
      //}
      }
	}
}

int main() {

  //  Creacion de objeto de tipo arbol binario de busqueda
  CArbol_BST miArbolitoBonito;

	//  Se crea un objeto de la clase COrdenamineto_QuickSort que nos va a permitir acceder a la función de ordenamiento 
	COrdenamineto_QuickSort elemento_ordenador;
	//  Creamos un objeto de la clase CTokenize que nos permita tokenizar los elementos de la lista 
	CTokenize token;

	//  Usando la clase ifstream podremos abrir y manipular los archivos de manera sencilla
	cout << "Abriendo archivo de fallas en el servidor..." << endl;
	ifstream file("bitacora.txt");	//Con esta función abrimos el archivo
	string cadena;

	//  Definimos los vectores de tipo string donde almacenaremos nuestras cadenas de texto
	vector<string> elementos;
	vector<string> vector_cadena;
	vector<string> ips;

  //Vector en el que se almacenaran todas las direcciones ordenadas como strings 
  vector<string> Direcciones_ips;  

  /*Vector que ayuadra para que se pueda hacer el ordenamiento de las direcciones
    ip y en donde se hara la comprobacion si hay repetidos*/ 
  vector<string> Solo_direcciones; 

	//  Definimos los vectores de tipo entero donde almacenaremos cada octeto de las direcciones IPs
	vector<int>ip_primer_octeto;
	vector<int>ip_segundo_octeto;
  vector<int>ip_tercer_octeto;

	//  En este vector estaran almacenados todas las direcciones ips
	vector<int>lista_ip_totales;

	//  Se crea un objeto estatico de tipo CDirecciones_IP que nos ayudara a mandar los elementos al constructor 
	CDirecciones_IP fallas;

	/*  Definimos una variable contadora que nos ayudara a tomar control sobre cuantas veces se repite
  	  el ciclo con la apertura del archivo */
	int i = 0;

	//  Con este ciclo se abrirá el archivo y se recorreran todas las lineas que se encuentren en el archivo
	while (!file.eof()) //O(n)
	{
		elementos.clear();
		getline(file, cadena);

		vector_cadena.push_back(cadena);

		//  Se utiliza la funcion "tokenize" para poder separar los elementos siempre que haya un espacio

    token.tokenizar(cadena, ' ', elementos);//Ya que han separado los mandamos a el vector "elementos"

    Solo_direcciones.push_back(elementos[3]);
  	ips.clear();

		/*  Ya que nos encontramos en el cuarto elemento de las separaciones(las cuales son las direcciones ips)
	  	  volveremos a usar el tokenize pero ahora para hacer las separaciones por octetos*/
		token.tokenizar(elementos[3], '.', ips);

		//  La razon por la que se separan solo tres octettos es que el cuarto es separado con dos puntos (:)
		ip_primer_octeto.push_back(fallas.return_IP_numerica(ips[0]));
		ip_segundo_octeto.push_back(fallas.return_IP_numerica(ips[1]));
		ip_tercer_octeto.push_back(fallas.return_IP_numerica(ips[2]));
    
    /*  Se multiplican los octetos por numeros grandes para poder realizar una comparacion entre ellos, se realizo esto, ya que 
        podria ser mas facil que emplear una funcion de comparacion entre direcciones ip */
     
		lista_ip_totales.push_back(ip_primer_octeto[i] * 100000 + ip_segundo_octeto[i] * 1000 + ip_tercer_octeto[i]);

		i++; //El contador nos ayuda a conocer la "longitud" de las direcciones ip
	}
	file.close();


	/*  Una vez que tengamos todas las direcciones ip, usaremos nuestro objeto 'elemento_ordenador'
      para poder llamar al metodo de ordenamiento de la clase QuickSort*/

	elemento_ordenador.Ordenamiento_QuickSort(lista_ip_totales, Solo_direcciones, 0, i); // Se realiza el ordenamiento de las direcciones

  //Se agregan las direcciones ya ordenadas en el vector 'Direcciones_ips'
  for (int j = 1; j < Solo_direcciones.size()+1; j++) {
    Direcciones_ips.push_back(Solo_direcciones[j]);
  }

  
  //Se llama a la funcion que comprueba repetidos
  comprueba_repetidos(Direcciones_ips,miArbolitoBonito);

  //De las direcciones repetidas se genera el top 5 de las direcciones con mayor repeticion 
  miArbolitoBonito.In_Orden_Inverso();
  miArbolitoBonito.Primeros_Cinco();

  //---------------------------------Abriendo un nuevo archivo--------------------------------

  /* Se crea un nuevo archivo donde se desplegaran unicamente las direcciones ip ordenadas en orden ascendente, eso para poder ver 
      las direcciones de una forma mas visual y revisar las direcciones que se han repetido*/

  ofstream archivo; 

	archivo.open("Direcciones_Ip_Ordenadas.txt", ios::out);		// Se crea el nuevo archivo en donde se van a desplegar las direcciones Ip ordenadas
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
  for (int j = 0; j < Direcciones_ips.size(); j++) {
			archivo << Direcciones_ips[j] << endl;
	}

  archivo.close(); //Se cierra el achivo 
}
	


#include "CDirecciones_IP.h"
using namespace std;

CDirecciones_IP::CDirecciones_IP(vector<string> elementos) {//Complejidad: O(n)
	ip = elementos[3];

}

int CDirecciones_IP::return_IP_numerica(string elemento) { //Complejidad: O(n)
  ip= elemento;
  return atoi(ip.c_str());
}
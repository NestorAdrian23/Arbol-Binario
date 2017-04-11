#include <iostream>


using namespace std;
class NodoP
{
public:
	NodoP* Padre;
	NodoP* izq, *der;
	int Dato;

	NodoP(int Dato, NodoP* Padre);
	NodoP(int Dato);

};
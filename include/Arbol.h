#include "NodoP.h"

class Arbol
{
	public:
	NodoP* Raiz;
	Arbol(int Dato);
	Arbol();
	NodoP* InsertarN(int Ref, NodoP* aux);
	NodoP* Buscar(int Ref, NodoP* aux);
	NodoP* nodoDer(NodoP* aux);
	bool Insertar(int Dato);
	bool Eliminar(int Ref);
};
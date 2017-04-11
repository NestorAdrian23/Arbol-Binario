#include "Arbol.h"

NodoP::NodoP(int Dato, NodoP* Padre)
{
	this->Dato= Dato;
	this->Padre= Padre;
}

NodoP::NodoP(int Dato)
{
	this->Dato=Dato;
	this->Padre=NULL;
}


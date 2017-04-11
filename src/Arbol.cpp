#include "Arbol.h"

Arbol::Arbol(int Dato)
{
	this->Raiz= new NodoP(Dato);
}

Arbol::Arbol()
{
	this->Raiz=NULL;
}

NodoP* Arbol::InsertarN(int Ref, NodoP* aux)
{
	if(aux->Dato >Ref)
	{
		if(aux->izq== NULL )
			return aux;
		return InsertarN(Ref, aux->izq);
	}
	else
	{
		if(aux->der==NULL)
			return aux;
		return InsertarN(Ref, aux->der);
	}
	
}

NodoP* Arbol::Buscar(int Ref, NodoP* aux)
{
	if(aux->Dato==Ref)
		return aux;
	if(aux->Dato < Ref && aux->der !=NULL)
		return Buscar(Ref, aux->der);
	else if(aux->Dato > Ref && aux->izq != NULL)
		return Buscar(Ref, aux->izq);
}

bool Arbol::Insertar(int Dato)
{
	if(Buscar(Dato, this->Raiz) != NULL)
	{
		cout<<"Error"<<endl;
		return false;
	}
	NodoP* auxiliar= InsertarN(Dato, this->Raiz);
	NodoP* hijo= new NodoP(Dato, auxiliar);
	if(auxiliar->Dato > Dato)
		auxiliar->izq= hijo;
	else
		auxiliar->der= hijo;
	return true;
}

NodoP* Arbol::nodoDer(NodoP* aux)
{
	if (aux->der!=NULL)
	{
		return nodoDer(aux->der);
	}
	return aux;
}

bool Arbol::Eliminar(int Ref)
{
	NodoP* aux= Buscar(Ref, this->Raiz);
	if(aux==NULL)
	{
		cout<<"Error"<<endl;
		return false;
	}
	if(aux->der==NULL && aux->izq==NULL)
	{
		if(aux==aux->Padre->izq)
			aux->Padre->izq=NULL;
		else
			aux->Padre->der=NULL;
		aux->Padre=NULL;
		return true;
	}
	if(aux->izq==NULL)
	{
		if(aux=aux->Padre->izq)
		{
			aux->Padre->izq=aux->der;
		}
		else
			aux->Padre->der=aux->Padre;
		aux->der->Padre=aux->Padre;
		aux->Padre=NULL;
	}
	else
	{
		if(aux->izq->der==NULL)
		{
			aux->izq->der=aux->der;
			aux->izq->Padre=aux->Padre;
			if(aux==aux->Padre->izq)
				aux->Padre->izq=aux->izq;
			else
				aux->Padre->der=aux->izq;
			
			aux->der->Padre=aux->izq;
			aux->der=NULL;
			aux->izq=NULL;
			aux->Padre=NULL;
		}
		else
		{
			NodoP* aux1= nodoDer(aux->izq);
			if(aux1->izq !=NULL)
			{
				aux1->Padre=aux->Padre;
				aux->izq->Padre=aux1;
				aux->izq=aux->izq;
			}
			aux1->Padre=aux->Padre;
			aux->izq->Padre=aux1;
			aux->izq=aux->izq;

			if (aux->der != NULL)
			{
				aux1->der=aux->der;
				aux1->der->Padre=aux1;
			}
			if (aux==aux->Padre->izq)
			{
				aux1->Padre->izq=aux1;
			}
			else
			{
				aux1->Padre->der=aux1;
			}
			aux->der=NULL;
			aux->izq=NULL;
			aux->Padre=NULL;
		}
	}
}


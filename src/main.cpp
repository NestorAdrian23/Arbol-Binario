#include "Arbol.h"

using namespace std;

int main()
{
	int Dato,contador;
	Arbol arbol(Dato);
	bool repeticion=true;
	cout<<"Arbol Binario"<<endl;
	do
	{
		cout<<"inserta un valor"<<endl;
		cin>>Dato;
		arbol.Insertar(Dato);
		cout<<"Preciona 1 para repetir"<<endl;
		cin>>contador;
		if(contador==1)
			repeticion=false;
	} while (repeticion=true);

	cout<<"Valores insertados"<<endl;

	return 0;
}
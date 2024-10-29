#include <iostream>

using namespace std;

/**
 Este es u codigo que trata sobre pila en este codigo se almacena datos. se quitan datos y se puede ver el historial
**/

//Se define la estructura del nodo
struct nodo {
	int dato;//Almacena en dato en el nodo
	nodo* sig;//Almacena la direccion del siguiente nodo
};

/**Tipo de dato abstracto**/
typedef nodo* P;
//Tipo de dato nuevo es P

void pushAPila(P& p, int numero)
{
	//p es el puntero ancla
	P temp; //puntero auxiliar para
	//ayudar a moverme en la pila
	//Reacion del nodo
	temp = new nodo;/**Reconocemos temp como parte de la estructura**/
	temp->dato = numero;
	temp->sig = p;
	//fin de creacion de nodo
	p = temp;//Se asigna el nodo a la pila
}

int pop(P& pila)
{
	int n;
	P temp;
	temp = pila;
	n = temp->dato;
	pila = temp->sig;
	delete(temp);
	return n;

}

void mostrarPila(P pila)
{
	P temp;
	temp = pila;//le asigno la primer direccion de la pila
	while (temp != NULL)
	{
		cout << endl << temp->dato << endl;
		temp = temp->sig;//Pasamos al siguiente nodo
	}
}

void destruirPila(P& pila)
{
	P temp;
	while (pila != NULL)
	{
		temp = pila;
		pila = temp->sig;
		delete(temp);
	}
	cout << endl << "Pila eliminada..." << endl;
}

int main()
{
	//Puntero ancla
	P pila = NULL;//nodo * pila = NULL;
	int numero, opc;

	do {
		cout << "Menu PILAS" << endl << endl <<
			"1 Push (Apilar)" << endl <<
			"2 Pop (Desapilar)" << endl <<
			"3 Mostrar pila" << endl <<
			"4 Borrar pila" << endl <<
			"0 Salir" << endl << endl <<
			"Ingresa una opcion: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << endl << "Ingresa un numero: ";
			cin >> numero;
			//se envia puntero y dato desde teclado
			pushAPila(pila, numero);
			break;
		case 2:
			numero = pop(pila);
			cout << endl << "Se elimino el nodo con el numero: " << numero;
			break;
		case 3:
			if (pila != NULL)
				mostrarPila(pila);
			else
				cout << endl << "La pila esta vacia.." << endl;
			break;
		case 4:
			destruirPila(pila);
			break;
		case 0:
			cout << endl << "Saliendo del programa" << endl;
			break;
		default:
			cout << endl << "La opcion no existe..." << endl;
			break;
		}
	} while (opc != 0);

	return 0;
}
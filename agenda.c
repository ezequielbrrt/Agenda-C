#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pNodo nuevo,actual;


void push(Lista *lista,char *nomb,unsigned long long int tel,int edad,char *correo){
	nuevo=(pNodo)malloc(sizeof(tipoNodo));
	nuevo->nombre=(char*)malloc(sizeof(char)*strlen(nomb));
	nuevo->nombre=nomb;
	nuevo->tel=tel;
	nuevo->edad=edad;
	nuevo->correo=correo;

	actual=*lista;
	if(actual)while(actual->anterior)actual=actual->anterior;
	if(!actual||actual->edad>edad){
		nuevo->siguiente=actual;
		nuevo->anterior=NULL;
		if(actual)actual->anterior=nuevo;
		if(!*lista)*lista=nuevo;
	}
	else{
		while(actual->siguiente && actual->siguiente->edad<=edad)
			actual=actual->siguiente;
		nuevo->siguiente=actual->siguiente;
		actual->siguiente=nuevo;
		nuevo->anterior=actual;
		if(nuevo->siguiente)nuevo->siguiente->anterior=nuevo;
	}
	
}

void imprimir(Lista lista){
	//pNodo nodo=lista;

	if(!lista)printf("Lista vacia\n");

	//nodo=lista;
	while(lista->anterior)lista=lista->anterior;
		printf("Nombre   Numero    Edad   Correo");
	while(lista!=NULL){
		printf("\n%s, %llu,",lista->nombre,lista->tel);
		printf(" %d, %s",lista->edad,lista->correo);
		lista=lista->siguiente;
	}
}

void borrar(Lista *lista,int edad){

	pNodo nodo;

	nodo=*lista;
	while(nodo && nodo->edad<edad)nodo=nodo->siguiente;
	while(nodo && nodo->edad>edad)nodo=nodo->anterior;

	if(!nodo||nodo->edad!=edad)return;

	if(nodo==*lista)
		if(nodo->anterior)*lista=nodo->anterior;
		else *lista=nodo->siguiente;

	if(nodo->anterior)
		nodo->anterior->siguiente=nodo->siguiente;
	if(nodo->siguiente)
		nodo->siguiente->anterior=nodo->anterior;
	free(nodo);
}



#ifndef AGENDA_H
#define AGENDA_H
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 0
#define ERROR 1
#define ASCENDENTE 1
#define DESCENDENTE 0


typedef struct Nodo{
	char *nombre;
	unsigned long long int tel;
	int edad;
	char *correo;
	struct Nodo *siguiente;
	struct Nodo *anterior;	
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;


void push(Lista *lista,char *nomb,unsigned long long int tel,int edad,char *correo);
void imprimir(Lista lista);
void borrar(Lista *lista,int edad);

#endif

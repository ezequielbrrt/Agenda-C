#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	

	int op;
	char nomb[30];
	unsigned long long int tel;
	int edad,edad2;
	char correo[30];
	FILE *cfPtr; 
	Lista lista =NULL;
	pNodo p;


	
while(op!=7){
	printf("\n\nPrograma que organiza una agenda\n\n\n"); 
	printf("Selecciona alguna opcion\n");
	printf("1.Leer lista\n");
	printf("2.Ingresar nuevos elementos a la lista\n");
	printf("3.Imprimir lista\n");
	printf("4.Eliminar datos de la lista\n");
	printf("5.Salir\n");
	scanf("%d",&op);

	switch(op){
		case 1:
			if ((cfPtr = fopen("Agenda.txt", "r")) == NULL)
				printf("El archivo no se pudo abrir\n");
			else{
				printf("%s %s %s %s\n", "Nombre  ", "Numero  ","Edad ","Correo");
				fscanf(cfPtr, "%s %llu %d %s", nomb, &tel, &edad, correo);
			
				while(!feof(cfPtr)){
					printf("%s %llu %d    %s\n", nomb, tel, edad, correo);
					push(&lista,nomb,tel,edad,correo);
					fscanf(cfPtr, "%s %llu %d %s", nomb, &tel, &edad, correo);			
				}
				fclose(cfPtr);
				
			}
			break;
		case 2:
			printf("\nEscribe el nombre:");
			scanf("%s",nomb);
			printf("\nEscribe el telefono:");
			scanf("%llu",&tel);
			printf("\nEscribe la edad:");
			scanf("%d",&edad);
			printf("\nEscribe el correo:");
			scanf("%s",correo);
			push(&lista,nomb,tel,edad,correo);
			break;
		case 3:
			imprimir(lista);
			break;
		case 4:
			printf("Escribe el elemento a borrar \n");
			scanf("%d",&edad2);
			borrar(&lista,edad2);
			break;
		case 5:
			return 0;
		default:
			printf("\nError\n");
			break;

	}
}

}






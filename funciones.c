#include "defPacientes.h"
/**
 * @file
 * @brief
 * @author
 * @date
 * @param
 * @return
 */

nodo *anexarNodo(info dat, nodo *pt){
	nodo *aux, *nuevo;

	aux=pt;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo==NULL){
		printf("ERROR: Memoria no disponible\n");
		exit(1);
	}
	nuevo->paciente=dat;
	if(pt!=NULL){
		while(aux->next!=pt){
			aux=aux->next;
		}
		aux->next=nuevo;
		nuevo->next=pt;
	}else{
		pt=nuevo;
		nuevo->next=pt;
	}

	return pt;
}

//TODO Agregar info

void imprimirActual(nodo *pt){
	printf("%s\t%s\t%i\t%c\n", pt->paciente.nombre, pt->paciente.direccion, pt->paciente.telefono, pt->paciente.covid);

	return;
}

//TODO Agregar info

nodo *recorrerNodo(nodo *pt){
	pt=pt->next;

	return pt;
}

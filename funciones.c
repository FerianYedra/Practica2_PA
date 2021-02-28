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

//TODO Agregar info

void imprimirCovid(nodo *pt){
	nodo *aux;
	
	aux=pt;
	if(pt==NULL){
		printf("La Lista esta vacía\n");
	}else{
		do{
			if(aux->paciente.covid==115){
				imprimirActual(aux);
			}
			aux=aux->next;
		}while(aux!=pt);
	}

	return;
}

//TODO Agregar info

void modificarActual(nodo *pt){
	printf("Nombre del Alumno: ");
	scanf(" %[^\n]", pt->paciente.nombre);
	printf("Dirección del alumno: ");
	scanf(" %[^\n]", pt->paciente.direccion);
	printf("Teléfono del alumno: ");
	scanf(" %i", &pt->paciente.telefono);
	printf("Tiene covid (s/n): ");
	scanf(" %c", &pt->paciente.covid);

	return;
}

//TODO Agregar info

void guardarBinario(nodo *pt){
	FILE *fp;
	nodo *aux;

	aux=pt;
	fp=fopen("pacientes.bin", "wb");
	if(fp==NULL){
		printf("ERROR: Archivo no diponible\n");
		exit(1);
	}
	do{
		fwrite(&aux->paciente, sizeof(info), 1, fp);
		aux=aux->next;
	}while(aux!=pt);
	fclose(fp);
	printf("Archivo guardado\n");

	return;
}

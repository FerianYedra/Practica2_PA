#include "defPacientes.h"
/**
 * @file funcione.c
 * @brief Esta función recibe los datos de los pacientes en orden y los va agregando a una lista
 * 	  circular dinámica.
 * @author Fernando Ian Yedra Lavalle
 * @date /28/02/2021
 * @param dat	Es una estrucutra info que incluye los datos a guardar.
 * @param *pt	Es el nodo de referencia al inicio de la lista.
 * @return *pt	Devuelve el inicio de la lista.
 */

nodo *anexarNodo(info dat, nodo *pt){
	nodo *aux, *nuevo;
	int letra=65;

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

/**
 * @brief Esta función imprime los datos del alumno en donde se encuentre la lista con el fomrato:
 * 	  <Nombre>	<Dirección>	<Teléfono>	<s/n>
 * @author Fernando Ian Yedra Lavalle
 * @date 28/02/2021
 * @param *pt	Es el nodo actual donde se encuentra la lista.
 * @return void
 */

void imprimirActual(nodo *pt){
	printf("%s\t%s\t%i\t%c\n", pt->paciente.nombre, pt->paciente.direccion, pt->paciente.telefono, pt->paciente.covid);

	return;
}

/**
 * @brief Esta función recorre al siguiente lugar en la lista.
 * @author Fernando Ian Yedra Lavalle
 * @date 28/02/2021
 * @param *pt 	Es el nodo acutal donde se encuentra la lista.
 * @return *pt	Es el nodo ya recorrido en la lista.
 */

nodo *recorrerNodo(nodo *pt){
	pt=pt->next;

	return pt;
}

/**
 * @brief Esta función recorre toda la lista, si encuentra un alumno con covid lo manda a imprimir.
 * @author Fernando Ian Yedra Lavalle
 * @date 28/02/2021
 * @param *pt	Es la referencia al inicio de la lista.
 * @return void
 */

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

/**
 * @brief Esta función recupera los datos ingresados del usuario y los guarda en el nodo actual.
 * @author Fernando Ian Yedra Lavalle
 * @date 28/02/2021
 * @param *pt	Es la referencia al nodo actual.
 * @return void
 */

void modificarActual(nodo *pt){
	int check=0;

	while(check!=1){
		printf("Nombre del Alumno: ");
		scanf(" %[^\n]", pt->paciente.nombre);
		printf("Dirección del alumno: ");
		scanf(" %[^\n]", pt->paciente.direccion);
		printf("Teléfono del alumno: ");
		scanf(" %i", &pt->paciente.telefono);
		printf("Tiene covid (s/n): ");
		scanf(" %c", &pt->paciente.covid);
		if(pt->paciente.covid==99||pt->paciente.covid==110){
			check=1;
		}
		else{
			printf("Error al ingresar datos, intente denuevo\n");
		}
	}
	return;
}

/**
 * @brief Esta función recorre toda la lista y guarda los alumnos en un archivo binario de nombre
 * 	  "paciente.bin".
 * @author Fernando Ian Yedra Lavalle
 * @date 28/02/2021
 * @param *pt Es el nodo referencia al inico de la lista.
 * @return void
 */

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

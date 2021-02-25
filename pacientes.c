/**
 * @file
 * @brief
 * @author
 * @date
 */

#include "defPacientes.h"
//TODO Incluir prototipos
nodo *anexarNodo(info dat, nodo *pt);
void imprimirActual(nodo *pt);
nodo *recorrerNodo(nodo *pt);

int main(int argc, char *argv[]){
	char opcion;
	info alumno;
	nodo *inicio;
	FILE *fp;
	int i=0;
	
	inicio=NULL;
	printf("-----Catálogo de alumnos------\n");
	if(strcmp(argv[1],"-t")==0){
		printf("Leyendo archivo %s\n", argv[2]);
		fp=fopen(argv[2], "r");
		if(fp==NULL){
			printf("Archivo no disponible\n");
			exit(1);
		}
		while(fscanf(fp, "%[^\t] %[^\t] %i %c \n", alumno.nombre, alumno.direccion, &alumno.telefono, &alumno.covid)==4){
			inicio=anexarNodo(alumno, inicio);
			i++;
			//TODO Función para colorar en orden alfabético
		}
		printf("Se leyeron %i alumnos\n", i);
		fclose(fp);
	}else if(strcmp(argv[1],"-b")==0){
		printf("Recuperando catálogo guardado\n");
		//TODO Función para recuperar del binario (puede ser la misma)
	}else{
		printf("ERROR: Selección de comando inválida, saliendo del programa\n");
		return 1;
	}
	while(opcion!='s'){
		printf("---MENU---\n");
		printf("----------------------------\n");
		printf("Datos del alumno:\n");
		imprimirActual(inicio);
		printf("----------------------------\n");
		printf("(r) - Recorrer lista\n");
		printf("(m) - Modificar paciente actual\n");
		printf("(c) - Mostrar alumnos con covid\n");
		printf("(s) - Salir\n");
		printf("Seleccionar opción: ");
		scanf(" %c", &opcion);
		switch(opcion){
			case 'r':
				printf("\nRecorriendo paciente\n\n");
				inicio=recorrerNodo(inicio);
				break;
			case 'm':
				printf("\nModificar paciente\n\n");
				//TODO Funcion para modificar nodo actual
				break;
			case 'c':
				//TODO Función para imprimir pacientes con prioridad para covid
				break;
			case 's':
				printf("Saliendo del programa...\n");
				break;
			default:
				printf("Opción inválida");
				break;
		}
	}
	//TODO Función para guardar el arvhivo binario
	return 0;
}

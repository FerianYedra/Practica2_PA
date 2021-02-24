/**
 * @file
 * @brief
 * @author
 * @date
 */

#include "defPacientes.h"
//Incluir prototipos

int main(int argc, char *argv[]){
	char opcion;
	info alumno;
	nodo *inicio=NULL;
	FILE *fp;

	//TODO Cambiar switch por if
	printf("-----Catálogo de alumnos------\n");
	switch(argv[1][0]){
		case 't':
			printf("Leyendo archivo %s\n", argv[2]);
			fp=fopen(argv[2], "r");
			if(fp==NULL){
				printf("Archivo no disponible\n");
				exit(1);
			}
			while(fscanf(fp, " %[^\t] %[^\t] %i %c\n", alumno.nombre, alumno.direccion, &alumno.telefono, &alumno.covid)==4){
				printf("leer\n");//TODO Solo para verificar que pase
				//TODO Función para anexar nodo (alumno, inicio)
			}
			fclose(fp);
			break;
		case 'b':
			printf("Recuperando catálogo guardado\n");
			//TODO Función para recuperar delbinario (puede ser la misma)
			break;
	}
	while(opcion!='s'){
		printf("---MENU---\n");
		printf("----------------------------\n");
		//TODO Función para imprimir nodo actual
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
				//TODO Función par recorrer paciente
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
	
	return 0;
}

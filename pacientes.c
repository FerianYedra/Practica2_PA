/**
 * @file
 * @brief
 * @author
 * @date
 */

#include "defPacientes.h"
//TODO Incluir prototipos

int main(int argc, char *argv[]){
	char opcion;
	info alumno;
	nodo *inicio=NULL;
	FILE *fp;
	printf("%i\n",strcmp(argv[1],"-b"));
	printf("-----Catálogo de alumnos------\n");
	if(strcmp(argv[1],"-h")==1){
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
	}else if(strcmp(argv[1],"-b")==1){
		printf("Recuperando catálogo guardado\n");
		//TODO Función para recuperar delbinario (puede ser la misma)
	}else{
		printf("Selección de comando inválida, salienod del programa\n");
		return 1;
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
	//TODO Función para guardar el arvhivo binario
	return 0;
}

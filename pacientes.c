/**
 * @file pacientes.c
 * @brief Este programa tiene la intencion de guardar y modificar una lista dinámica circuialr de
 * 	  peronas/alumnos y clasificarlos en caso de que presenten covid. programa se puede
 * 	  ejecutar con un -t para leer un archivo de nombre "pacientes.txt", este archivo se puede
 * 	  modificar desde fuera, tiene que tener la siguiente estructura:
 * 	  <Nombre>\t<Dirección>\t<Teléfono>\t<s/n>\n
 * 	  De otra forma el archivo se puede ejecutar con un -b, este archivo se actualiza cada vez
 * 	  que se cierra el programa, el arhivo lleva nombre de "pacientes.bin".
 * 	  Cada vez que el programa lee el archivo crea la lista con los nombres ordenados de A-Z.
 * 	  Dentro del menu se puede recorrer la lista, modificar el paciente actual, mostrar los
 * 	  alumnos con covid (en rojo) y salir del programa.
 * @author Fernando Ian Yedra Lavalle
 * @date 28/02/2021
 */

#include "defPacientes.h"
//TODO Incluir prototipos
nodo *anexarNodo(info dat, nodo *pt);
void imprimirActual(nodo *pt);
nodo *recorrerNodo(nodo *pt);
void imprimirCovid(nodo *pt);
void modificarActual(nodo *pt);
void guardarBinario(nodo *pt);

int main(int argc, char *argv[]){
	char opcion;
	info alumno;
	nodo *inicio;
	FILE *fp;
	int i=0,j;
	
	inicio=NULL;
	printf("-----Catálogo de alumnos------\n");
	if(strcmp(argv[1],"-t")==0){
		printf("Leyendo archivo pacientes.txt\n");
		fp=fopen("pacientes.txt", "r");
		if(fp==NULL){
			printf("Archivo no disponible\n");
			exit(1);
		}
		fclose(fp);
		for(j=0;j<=26;j++){
			fp=fopen("pacientes.txt", "r");
			while(fscanf(fp, "%[^\t] %[^\t] %i %c \n", alumno.nombre, alumno.direccion, &alumno.telefono, &alumno.covid)==4){
				if(alumno.nombre[0]==65+j){
					inicio=anexarNodo(alumno, inicio);
					i++;
				}
			}
			fclose(fp);
		}
		printf("Se leyeron %i alumnos\n", i);
	}else if(strcmp(argv[1],"-b")==0){
		printf("Leydendo archvio pacientes.bin\n");
		fp=fopen("pacientes.bin", "rb");
		if(fp==NULL){
			printf("Archivo no disponible\n");
			exit(1);
		}
		fclose(fp);
		for(j=0;j<=26;j++){
			fp=fopen("pacientes.bin","rb");
			while(fread(&alumno,sizeof(info),1,fp)==1){
				if(alumno.nombre[0]==65+j){
					inicio=anexarNodo(alumno, inicio);
					i++;
				}
			}
			fclose(fp);
		}
		printf("Se leyeron %i alumnos\n",i);
	}else if(argv[1]==NULL){
		printf("ERROR: Selección de comando inválida, saliendo del programa\n");
		return 1;
	}else{
		printf("ERROR: Selección de comando inválida, saliendo del programa\n");
		return 2;
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
				modificarActual(inicio);
				break;
			case 'c':
				printf("\033[0;31m");
				printf("-----Alumnos con covid-----\n");
				imprimirCovid(inicio);
				printf("\033[0m");
				break;
			case 's':
				guardarBinario(inicio);
				printf("Saliendo del programa...\n");
				break;
			default:
				printf("Opción inválida\n");
				break;
		}
	}

	return 0;
}

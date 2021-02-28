/**
 * @file defPaciente.h
 * @brief Este archivo es la cabecera del programa incluye los directorios de stdio.h, stdlib.h
 *	  y string.h, también contiene las estructuras para los pacientes (info) y la estructura
 *	  para los nodos (nodo).
 * @author Fernando Ian Yedra Lavalle
 * @date 28/02/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos{
	char nombre[80];
	char direccion[80];
	int telefono;
	char covid;
};
typedef struct datos info;

struct elemento{
	info paciente;
	struct elemento *next;
};
typedef struct elemento nodo;

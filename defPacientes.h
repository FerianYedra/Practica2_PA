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

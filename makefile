pcientes.exe:pacientes.o funciones.o
	gcc pacientes.o funciones.o -o pacientes.exe

pacientes.o:pacientes.c
	gcc -c pacientes.c

funciones.o:funciones.c
	gcc -c funciones.c

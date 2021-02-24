pcientes.exe:pacientes.o
	gcc pacientes.o -o pacientes.exe

pacientes.o:pacientes.c
	gcc -c pacientes.c

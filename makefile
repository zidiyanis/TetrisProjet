all : exec run


exec : main.o fonctionMain.o fonction.o
	gcc main.o fonctionMain.o fonction.o -o exec

main.o : main.c fonction.h fonctionMain.h
	gcc -c main.c -o main.o

fonctionMain.o : fonctionMain.c fonction.h   fonctionMain.h
	gcc -c fonctionMain.c -o fonctionMain.o

fonction.o : fonction.c fonction.h
	gcc -c fonction.c -o fonction.o

clean :
	rm -f *.o
	rm exec

run:
	./exec

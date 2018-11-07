CFLAGS = -Wall\
		 -ansi\
		 -pedantic\
		 -lgraph\
		 -lm

OFILES = main.o menu.o jeu.o autre.o image.o

Projet : $(OFILES)
	gcc -o Projet $(OFILES) $(CFLAGS)
image.o : image.h
	gcc -c image.c
autre.o : autre.h
	gcc -c autre.c
jeu.o : jeu.h
	gcc -c jeu.c
menu.o : menu.h
	gcc -c menu.c
main.o : main.c
	gcc -c main.c
clean :
	rm -f Projet $(OFILES)

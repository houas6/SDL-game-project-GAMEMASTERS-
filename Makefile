game:func.o main.o 
	gcc func.o main.o -o game -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c 
	gcc -c main.c -g
fonction.o:func.c 
	gcc -c fonction.c -g 
	

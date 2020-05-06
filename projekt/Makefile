
CC=g++	

		
all: mainprojektu.o menu.o
	
	$(CC) mainprojektu.o menu.o -o sfml-app -L/home/endzi2/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system	

menu.o: menu.cpp menu.h
	$(CC) menu.cpp -c -o menu.o
	
mainprojektu.o: mainprojektu.cpp
	$(CC) mainprojektu.cpp -c -o mainprojektu.o

clean:
	rm -f *.o sfml-app

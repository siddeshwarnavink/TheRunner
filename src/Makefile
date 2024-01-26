all: compile link run

compile:
	
	g++ -c main.cpp -I../include -DSFML_STATIC
	g++ -c engine/functions.cpp -I../include -DSFML_STATIC -o functions.o


link:
	
	g++ main.o functions.o -o main -L"..\\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -mwindows -lopengl32 -lfreetype -lwinmm -lgdi32

run:
	.\main

clean:
	rm -f main *.o
	g++ -c main.cpp -I"C:\\Users\\haris\\OneDrive\\Documents\\SFML-2.6.1\\include"
	g++ main.o -o main -L"C:\\Users\\haris\\OneDrive\\Documents\\SFML-2.6.1\\lib" -lsfml-graphics -lsfml-window -lsfml-system -mwindows
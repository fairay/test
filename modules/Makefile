all: main.exe

run: main.exe
	./main.exe

main.exe: main.o example.o
	gcc -o main.exe main.o example.o

example.o: example.c example.h
	gcc -c example.c

main.o: main.c example.h
	gcc -c main.c

clear:
	rm main.exe example.o main.o

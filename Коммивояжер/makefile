all: Hehehe.o src.o
	g++ Hehehe.o src.o -o myexe.exe

Hehehe.o: Hehehe.cpp
	g++ -c Hehehe.cpp -o Hehehe.o

src.o: src.cpp head.h
	g++ -c src.cpp -o src.o

clean:
	rm *.o

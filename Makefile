output: main.o randomstring.o creatures.o clist.o
	g++ main.o randomstring.o creatures.o clist.o -o output

main.o: main.cpp
	g++ -c main.cpp 

randomstring.o: randomstring.cpp randomstring.h
	g++ -c randomstring.cpp

creatures.o: creatures.cpp creatures.h
	g++ -c creatures.cpp

clist.o: clist.cpp clist.h
	g++ -c clist.cpp

clean:
	rm *.o output
    
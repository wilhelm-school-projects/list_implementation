

all: main.o Sorted_List.o
	g++ main.o Sorted_List.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

Sorted_List.o: Sorted_List.cpp
	g++ -c Sorted_List.cpp -o Sorted_List.o


.PHONY: clean

clean:
	rm *.o a.out
all:
	nasm -g -f elf64 -o ackerman.o ackerman.asm
	g++ -c -g -no-pie -o main.o main.cpp
	g++ -g -o casm ackerman.o main.o

debug:
	nasm -g -f elf64 -o ackerman.o ackerman.asm
	ld -o PROGRAMA ackerman.o ackerman.o

clean:
	rm *.o
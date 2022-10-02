all: hello

hello: hello.o
	gcc -o hello hello.o

hello.o: hello.cc
	gcc -c hello.cc

clean:
	rm hello.o hello


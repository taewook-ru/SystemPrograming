OBJECTS : add.o subtract.o multiply.o divide.o test.a test.so 


add.o : add.c
	gcc -c add.c

subtract.o : subtract.c
	gcc -c subtract.c

multiply.o : multiply.c
	gcc -c multiply.c

divide.o : divide.c
	gcc -c divide.c

clean : 
	rm -f *.o
	rm libtest.*
	rm libpr1.*



test.a : 
	ar rcs libtest.a add.o subtract.o multiply.o divide.o


test.so :
	gcc -shared -Wl,-soname,libpr1.so.0 -o libpr1.so.1.0.1 add.o subtract.o multiply.o divide.o
	ln -s libpr1.so.1.0.1 libpr1.so.0
	ln -s libpr1.so.1.0.1 libpr1.so

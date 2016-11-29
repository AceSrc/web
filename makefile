archieve = test_b.cpp test_c.cpp
runable : archieve.so
	gcc a.cpp -L. -larchieve -o runable
acetool.o : 
	gcc acetool.cpp -c acetool.h
archieve.so:
	gcc $(archieve) -fPIC -shared -o libarchieve.so
clean : 
	rm acetool.o 


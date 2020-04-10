clean:
	rm ./a.out

compile:
	gcc fsLowDriver.c
  
run:
	make clean
	make compile
	./a.out



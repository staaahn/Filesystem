clean:
	rm main

lowDriver:
	gcc fsLowDriver.c fsLow.c -o main -lm

ourDriver:
	gcc fsdriver3.c fsLow.c -o main -lm

runLow:
	./main output 16384 512

run:
	./main



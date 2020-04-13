clean:
	rm main
	rm volume

lowDriver:
	gcc fsLowDriver.c fsLow.c -o main -lm

ourDriver:
	gcc fsdriver3.c fsLow.c -o main -lm

runLow:
	make lowDriver
	./main volume 1048576 512

run:
	make ourDriver
	./main volume 1048576 512



clean:
	rm main
	rm volume

cleanHex:
	rm hex
	> hexdump_results.txt

cleanResults:
	> hexdump_results.txt

ourDriver:
	gcc fsdriver3.c low/fsLow.c tokenize/tokenize.c functions/touch/createFile.c -o main -lm

lowDriver:
	gcc fsLowDriver.c low/fsLow.c -o main -lm

hexdump:
	gcc hexdump.c -o hex

run:
	make ourDriver
	./main volume 1048576 512

runLow:
	make lowDriver
	./main volume 1048576 512

runHexdump:
	make hexdump
	(./hex volume) >> hexdump_results.txt 



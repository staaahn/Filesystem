#include <stdlib.h>
#include <stdint.h>
#include "bitMap.h"

BitMap* bitMapInit(uint32_t SizeInWords) {
	BitMap* bitMap = (BitMap*) malloc(sizeof(BitMap) * 1);
	// checks if the memory allocation failed
	if (bitMap == 0)
		return 0;

	bitMap->dataarray = (uint32_t*) malloc(sizeof(uint32_t) * SizeInWords);

	bitMap->bitsize = SizeInWords * WORDSIZE;
	bitMap->wordsize = SizeInWords;

	return bitMap;
}

// this function is used to help allocate a block to file, and sets that bit to 1
void SetBitSize(BitMap* map,  uint32_t BitNum) {
    // Set the bit at the k position in A[i]
    map->dataarray[BitNum/WORDSIZE] |= 1 << (BitNum%WORDSIZE);  
}

// frees a block from file, clears the bit and sets to 0
void clearBit(BitMap* map, uint32_t BitNum) {
   map->dataarray[BitNum/WORDSIZE] &= ~(1 << (BitNum%WORDSIZE));
}

bool testBit(BitMap* map, uint32_t BitNum) {
   return (bool) ((map->dataarray[BitNum/WORDSIZE] & (1 << (BitNum%WORDSIZE) )) != 0 ) ;
}

void bitMapDeInit(BitMap* map) {
	free(map->dataarray);
	free(map);

	map = 0;
}

#define WORDSIZE 32

typedef struct NNODEBitMap {
	uint32_t  bitsize;
	uint32_t  wordsize;

	uint32_t* dataarray;
} BitMap;

BitMap* bitMapInit(uint32_t SizeInWords);
void 	SetBitSize(BitMap* map,  uint32_t BitNum);
void 	clearBit(BitMap* map, uint32_t BitNum);
bool 	testBit(BitMap* map, uint32_t BitNum);
void 	bitMapDeInit(BitMap* map);

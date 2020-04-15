#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "bitMap.h"
#include "structure.h"

#define SECTOR_SIZE	512

BitMap* dataBitMap;
BitMap* inodeBitMap;

struct superBlock fileSysProp;

INODE CurrentNode;														
BYTE tempBlock[SECTOR_SIZE];	

void Init() {
    const struct SuperBlock PermanentSuperBlock = {MAX_INODE, MAX_BLOCKS, INODE_BLOCK_START};

    // Initialize with SuperBlock parameters 
	memset(&tempBlock, 0, SECTOR_SIZE);
	memcpy(&tempBlock, &PermanentSuperBlock, sizeof(struct SuperBlock));

    if (WriteToFile((BYTE*) &tempBlock, SUPER_BLOCK_SECTOR) == FALSE)
		exit(-1);

	dataBitMap = bitMapInit(DATA_BITMAP_SIZE);
	inodeBitMap = bitMapInit(INODE_BITMAP_SIZE);

    // Store the data bit map into the proper area
	SetBitSize(dataBitMap, SUPER_BLOCK_SECTOR; 		// The superblock location is taken.
	SetBitSize(dataBitMap, INODE_BITMAP_SECTOR;		// The inode bitmap block is taken.
	SetBitSize(dataBitMap, DATA_BITMAP_SECTOR);			// The data bitmap block is taken.

	for (int i = 0; i < TOTAL_INODE_SECTORS; i++)
		SetBitSize(dataBitMap, INODE_BLOCK_START + i);		// Mark all the inode sectors as occupied.

    memcpy(&tempBlock[0], dataBitMap, sizeof(BitMap) - sizeof(uint32_t*)); // stores everything

   	uint32_t used = sizeof(BitMap) - sizeof(uint32_t*);	// The amount of sized used so far in the struct

	memcpy(((&tempBlock[used])), dataBitMap->dataarray, DATA_BITMAP_SIZE * sizeof(uint32_t)); // Copy over the dynamic data

    if (WriteToFile((BYTE*) &tempBlock, DATA_BITMAP_SECTOR) == FALSE)
		exit(-1);

    memcpy(&tempBlock[0], inodeBitMap, sizeof(BitMap) - sizeof(uint32_t*));
    used = sizeof(BitMap) - sizeof(uint32_t*);
    memccpy(((&tempBlock[used])), inodeBitMap->dataarray, INODE_BITMAP_SIZE * sizeof(uint32_t)); // Copies dynamic data

    if (_WriteToFile((BYTE*) &tempBlock, INODE_BITMAP_SECTOR) == FALSE)
        exit(-1);

    // Delete the allocations
	BitMap_DeInit(DataBitMap);
	BitMap_DeInit(InodeBitMap);

	// Start creating and storing the inodes 
	uint32_t InodeIterator = 0;
	memset(&CurrentNode, 0, sizeof(INODE));

	for (uint32_t i = 0; i < TOTAL_INODE_SECTORS; i++) {
		for (uint32_t j = 0; j < INODES_PER_SECTOR; j++) {
			CurrentNode.INODE_NUM = (INODES_PER_SECTOR * i) + j;
			memcpy(&tempBlock[j * sizeof(INODE)], &CurrentNode, sizeof(INODE));
			memset(&CurrentNode, 0, sizeof(INODE));
		}

		if (WriteToFile((BYTE*) &tempBlock, INODE_BLOCK_START + i) == FALSE)	// Write to the proper inode sector location
			exit(-1);
	}
}
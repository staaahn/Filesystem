#define DRIVENUM 0
#define SUPER_BLOCK_SECTOR 0		// SuperBlock is located in this sector
#define INODE_BITMAP_SECTOR 1
#define DATA_BITMAP_SECTOR 2
#define INODE_BLOCK_START 3			// First inode is here 

#define MAX_INODE 3950			// Maximum number of files created 
#define MAX_BLOCKS 3950			// Maximum number of blocks begin tracked

#define DATA_BITMAP_SIZE ((MAX_BLOCKS_TRACKED/(sizeof(uint32_t)*8)) + 1)	// Number of n blocks 

// 1 bit per block for 32 bits per int.
#define INODE_BITMAP_SIZE ((MAX_INODE_COUNT/(sizeof(uint32_t)*8)) + 1)

#define SECTOR_SIZE	512
#define SIZE_OF_FLASHBLOCK SECTORSIZE

///////////////////////  inode properties  ////////////////////////////////////////////////////////////
#define MAX_FILE_SECTORS 22	            // max number of sectors for each file
#define MAX_FILE_NAME_CHARS	10			// max size of file names
#define INODE_SIZE	114
#define INODES_PER_SECTOR 4
#define TOTAL_INODE_SECTORS (MAX_INODE_COUNT/INODES_PER_SECTOR)

typedef struct FileNode {			         // Total: 114 bytes per inode
	uint32_t INODENUM;						 // 4 bytes
	uint32_t FILEBYTES;					 // 4 bytes; Increments of SECTOR_SIZE. Directly indicates how many blocks are used by file.
	uint32_t BYTESUSED;					 // 4 bytes; The amount of bytes used by data stored within the file. Once it hits n*SECTOR_SIZE, need to expand file
	uint32_t LATESTCURSOR;					 // 4 bytes; The last written area of file (so that append can start appending from there
	char FILENAME[MAX_FILE_NAME_CHARS];	 // 10 bytes
	uint32_t BLOCKSUSED[MAX_FILE_SECTORS];  // 88 bytes
} INODE;

typedef struct FileInfo {
	INODE* FileInode;				// Inode for the file
};

// Contains properties about the file system.
struct SuperBlock {
	uint32_t NumInodes;
	uint32_t NumDataBlocks;
	uint32_t InodeStartBlock;
};


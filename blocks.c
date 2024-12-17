/* blocks.h
 * structures and functions for different blocks to be used in game */

#include <FILE.h>

#define BSIZE 3

static const char INFILE [] = .blocks.csv;

/* i think it makes sense to have the active block (one that's currently
 * falling) allocated as a pointer (done in source file though), and a linked
 * list (w/ wrap) of possible blocks to pick the next block from */
// -> maybe try to store list of blocks as an array...

// idfk
typedef struct block	{
	int [2] ipt;	// x,y insert point of block
	int shape[BSIZE][BSIZE];
};

typedef struct blocklist	{
	block thisblock;
	blocklist* next;	
} *LIB_HEAD = NULL;

block rotate(block A)
{
	// apply pi/2 rotation to block A, e.g.,
	// [1 0 0]		[0 0 0]
	// [1 0 0] 	->	[0 0 1] 
	// [1 1 0]		[1 1 1]
	block B;
	B.ipt = A.ipt;

	// this probably isn't a great way to do this
	for (int j = 0; j < BSIZE; ++j)	{
		for (int i = 0; i < BSIZE; ++i)	{
			B.shape[j][i] = A.shape[i][BSIZE - j];
		}
	}
	return B;
}

void drop(block *A)
{
	A->ipt[0] -= 1;		
}

int addblock(block inblock)
{
	block* newblock = (block*)malloc(sizeof(block)); 
	if (newblock == NULL)
		return -1;	// error -> could not allocate memory
	blockcpy(newblock, inblock);
	if (LIB_HEAD == NULL)	{
		LIB_HEAD = newblock;
	} else	{
		block* cblock = LIB_HEAD;
		while (cblock->next != NULL)
			cblock = cblock->next;
		cblock = newblock;
	}	
	return 1;
}

void init_blocks()	{
	// go through file and initialize blocks
	// read line from file, try to make a block from it, then pass block
	// to addblock -> not sure if pointer should be created here or in addblock
}

// idk if i need this
void blockcpy(block *dest, block source)	
{
	dest->ipt[0] = source.ipt[0];
	dest->ipt[1] = source.ipt[1];
	
	int* destSP = dest->shape[0][0];
	int* blockSP = source.shape[0][0];
	for (i = 0; i < BSIZE * BSIZE; ++i)
		*destSP++ = *blockSP++;		// need to test this lol
}

block *getBlock(int seed)
{
	thisblock = LIB_HEAD;	// define a linked list of block types to pick from
	block *newBlock = (block*)malloc(sizeof(block));
	for (; seed >= 0; --seed)
		thisblock = thisblock->next;
	blockcpy(newblock, *thisblock);	
	return newblock;
}

void clearblocks()
{
	blocklist nblock = LIB_HEAD->next;
	while (LIB_HEAD != NULL)	{			
		free(LIB_HEAD);
		LIB_HEAD = nblock;
		nblock = LIB_HEAD->next;	
	}
}

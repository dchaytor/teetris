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

void init_blocks()	{
	// go through file and initialize blocks
}

// idk if i need this
void blockcpy(block *dest, block target)	{
	
}

block *getBlock(int seed)
{
	block *newBlock = (block*)malloc(sizeof(block));
	for (; seed >= 0; --seed)
		thisblock = thisblock.next;	
	return newblock
}

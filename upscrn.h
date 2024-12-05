/* <upscrn.h>
 * code with helper functions to handle screen update + printing */

#include <stdio.h>
#define OUTFILE stdout
#define MASK 0b10000000	// & this with element to decide if printing

extern char[][] screen;	// n x (m/8) matrix representing current screen state
extern short n;	// number of rows in matrix
extern short m; // number of cols in matrix
int elc = n * m; // el(ement )c(ount)


// define screen to be n*2m (since printing out blocks w/ 2 chars -> [])

static void _MVBLOCKS()
{
	// given the current state of the screen, update all falling blocks

	_PRINTSCRN();	// refresh screen with updated values
}

static void _PRINTSCRN()
{
	// print new screen over the old screen
	for (register int i = 0, char *pix = screen[0][0]; i < el; i += 8)	{
		// loop through bits in *pix L-R, and print to screen accordingly	
		for (bit = 0; bit < 8; ++bit)	{
			if (*pix & MASK)	 // should return true if not 0
				printf(OUTFILE, "[]");
			else	
				printf(OUTFILE, "  ");
		}
		if (i % m == 0) fprintf(OUTFILE, "\n");
		++pix;
	}
	fflush(outfile);	
}

public void upscrn()	
{



}

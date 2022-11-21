/***************************************

	Convert a binary file into an ASCII text dump. The dump is formatted
	into "C" source files.

	Copyright (c) 1995-2022 by Rebecca Ann Heineman <becky@burgerbecky.com>

	It is released under an MIT Open Source license. Please see LICENSE for
	license details. Yes, you can use it in a commercial title without paying
	anything, just give me a credit.

	Please? It's not like I'm asking you for money!

***************************************/

#include "vitacgdump.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 0x4000
#define MAXLINE 16

/***************************************

	Print the range as "C" hex source output
	The text takes the form of...
	\t0xXX,0xXX,0xXX,0xXX,\n

***************************************/

static void DumpCSource(const uint8_t* pBuffer, uintptr_t uCount)
{
	do {
		// Get the length of this run
		const uintptr_t uSize = (uCount < MAXLINE) ? uCount : MAXLINE;
		uCount -= uSize;

		// Line prefix
		printf("    ");
		unsigned int i = 0;
		do {
			if (i) { // Don't print the first time
				putchar(',');
			}
			printf("0x%02X", pBuffer[0]);
			++pBuffer;
		} while (++i < uSize);
		// Do I print the trailing comma?
		if (uCount) {
			putchar(',');
		}
		putchar('\n');
	} while (uCount);
}

/***************************************

	Perform a memory dump

***************************************/

int __cdecl main(int argc, const char** argv)
{
	int iResult = 10;

	// Usage
	if (argc != 2) {
		printf(
			"Usage: vitagc_dump InputFile\n\n"
			"Dumps the contents of a file to stdout.\n"
			"Copyright by Rebecca Ann Heineman\n");

	} else {

		FILE* fp = fopen(argv[1], "rb");
		if (!fp) {
			printf("Can't open the input file %s!\n", argv[1]);
		} else {

			fseek(fp, 0, SEEK_END);
			const size_t uSize = static_cast<size_t>(ftell(fp));
			fseek(fp, 0, SEEK_SET);
			void* pBuffer = malloc(uSize);
			if (pBuffer) {
				if (fread(pBuffer, 1, uSize, fp) == uSize) {
					DumpCSource(static_cast<uint8_t*>(pBuffer), uSize);
					iResult = 0;
				}
				free(pBuffer);
			}
			fclose(fp);
		}
	}
	return iResult;
}

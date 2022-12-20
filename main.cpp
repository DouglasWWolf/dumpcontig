//=================================================================================================
// dumpcontig - Dumps the reserved contiguous buffer to stdout
//
// Author: Doug Wolf
//
// To run this program, use this command line:
//     sudo ./dumpcontig | hd | more
//
//=================================================================================================

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <fcntl.h>
#include <cstring>
#include "PhysMem.h"

using namespace std;

PhysMem contigBuffer;   // Manages the reserved contiguous buffer

void execute();

//=================================================================================================
// main() - Dumps the contents of the contiguous buffer to stdout
//=================================================================================================
int main(int argc, char** argv)
{
    try
    {
        execute();
    }
    catch(const std::exception& e)
    {
        fprintf(stderr, "%s\n", e.what());
        exit(1);
    }
}
//=================================================================================================




//=================================================================================================
// execute() - Main-line execution
//=================================================================================================
void execute()
{
    // Map the contiguous buffer into user-space
    fprintf(stderr, "Mapping contiguous buffer...\n");
    contigBuffer.map();

    // Find out how big that buffer is
    size_t bufferSize = contigBuffer.getSize();

    // Fetch a pointer to the first byte of the buffer
    uint8_t* ptr = contigBuffer.bptr();

    while (bufferSize--)
    {
        putc(*ptr++, stdout);
    }
}
//=================================================================================================





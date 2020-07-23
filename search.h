/*
    Search file - contains functionality that will apply the search conditions to a specific 48 bit seed or the extension if that specific seed
    Should probably be called testing or something
*/

// 12 chunks. Limit would be 16, but as we can't calculate the exact position fo the portal room (too expensive), we remove 4 chunks to be sure.
#define CHUNKS_FROM_PORTAL 16 //192

// what is that lol
struct StructureCount
{
    int outpostCount;
};
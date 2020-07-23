#include "search.h"

// Whats this?

void checkStructure(int64_t seed, Pos strongholdPos, StructureConfig config, LayerStack g, struct StructureCount *count)
{
    Pos originalRegionPos = {
        strongholdPos.x >> 5,
        strongholdPos.z >> 5
    };

    /*
    Index 0: original region
    Index 1: X axis
    Index 2: Z axis
    Index 3: corner
    */
    Pos regionPositions[4];
    regionPositions[0] = originalRegionPos;
    int size = 1;
    // The type isnt used further down the line
    // ..whats the purpose of this code?
    //int type = configToStructureName(config);

    // X axis
    if (floor((strongholdPos.x + CHUNKS_FROM_PORTAL) / config.regionSize) != originalRegionPos.x)
    {
        regionPositions[1].x = originalRegionPos.x - 1;
        regionPositions[1].z = originalRegionPos.z;
        size++;
    }
    else if (floor((strongholdPos.x - CHUNKS_FROM_PORTAL) / config.regionSize) != originalRegionPos.x)
    {
        regionPositions[1].x = originalRegionPos.x + 1;
        regionPositions[1].z = originalRegionPos.z;
        size++;
    }

    // Z axis
    if (floor((strongholdPos.z + CHUNKS_FROM_PORTAL) / config.regionSize) != originalRegionPos.z)
    {
        regionPositions[2].x = originalRegionPos.x;
        regionPositions[2].z = originalRegionPos.z - 1;
        size++;
    }
    else if (floor((strongholdPos.z - CHUNKS_FROM_PORTAL) / config.regionSize) != originalRegionPos.z)
    {
        regionPositions[2].x = originalRegionPos.x;
        regionPositions[2].z = originalRegionPos.z + 1;
        size++;
    }

    // Corner
    if (size == 3)
    {
        regionPositions[3].x = regionPositions[1].x;
        regionPositions[3].z = regionPositions[2].z;
        size++;
    }

    /* Debug
    printf("[%d, %d], [%d, %d], [%d, %d], [%d, %d], size: %d\n",
        regionPositions[0].x,
        regionPositions[0].z,
        regionPositions[1].x,
        regionPositions[1].z,
        regionPositions[2].x,
        regionPositions[2].z,
        regionPositions[3].x,
        regionPositions[3].z,
        size);
    */

    for (int n = 0; n < size; n++)
    {
        Pos regionPos = regionPositions[n];
        Pos structureChunkRegion = getStructureChunkInRegion(DESERT_PYRAMID_CONFIG, seed, regionPos.x, regionPos.z);
        Pos structurePos = {
            regionPos.x * 32 + structureChunkRegion.x,
            regionPos.z * 32 + structureChunkRegion.z
        };

        int distanceX = abs(structurePos.x - strongholdPos.x);
        int distanceZ = abs(structurePos.z - strongholdPos.z);

        if (0 <= distanceX && distanceX <= CHUNKS_FROM_PORTAL / 2 && 0 <= distanceZ && distanceZ <= CHUNKS_FROM_PORTAL / 2)
        {
            // printf("{%d, %d}\n", structurePos.x * 16, structurePos.z * 16);
            count->outpostCount++;
        }
    }
}
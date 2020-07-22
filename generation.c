#include "generation.h"


void initGeneration() {
    initBiomes();
}

void getStrongholds(int64_t *seed, Pos *strongholds, LayerStack *g) {
    double d = nextDouble(seed) * PI * 2.0;
    int perRingCount = 0, m = 0, perRing = STRONGHOLD_SPREAD;
    int* validStrongholdBiomes = getValidStrongholdBiomes();

    for (int n = 0; n < STRONGHOLD_COUNT; n++)
    {
        double e = (4 * STRONGHOLD_DISTANCE + STRONGHOLD_DISTANCE * m * 6) + (nextDouble(seed) - 0.5) * STRONGHOLD_DISTANCE * 2.5;
        Pos chunk = {
            round(cos(d) * e),
            round(sin(d) * e)
        };

        Pos blockPos = findBiomePosition(MC_1_16, *g, NULL, (chunk.x << 4) + 8, (chunk.z << 4) + 8, 112, validStrongholdBiomes, seed, NULL);

        if (blockPos.x != (chunk.x << 4) + 8 && blockPos.z != (chunk.z << 4) + 8)
        {
            chunk.x = blockPos.x >> 4;
            chunk.z = blockPos.z >> 4;
        }

        strongholds[n] = chunk;

        d += PI * 2 / (double) perRing;
        perRingCount++;

        if (perRingCount == perRing)
        {
            m++;
            perRingCount = 0;
            perRing += 2 * perRing / (m + 1);
            perRing = (perRing >= STRONGHOLD_COUNT - n) ? STRONGHOLD_COUNT - n : perRing;
            d += nextDouble(seed) * PI * 2.0;
        }
    }
}

int configToStructureName(StructureConfig config)
{
    switch (config.seed)
    {
        case 165745296:         return Outpost;
        case 14357617:          return Desert_Pyramid;
        default:                return 0;
    }
}

Pos getPyramidPos(int64_t seed, int x, int z)
{
    int regionX = x;
    int regionZ = z;

    int64_t regionSeed = regionX * 341873128712 + regionZ * 132897987541 + seed + 14357617; //165745296;
    setSeed(&regionSeed);

    Pos pos = {
        regionX * 32 + nextInt(&regionSeed, 24),
        regionZ * 32 + nextInt(&regionSeed, 24)
    };

    return pos;
}
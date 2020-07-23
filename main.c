#include "main.h"

int main()
{
    initGeneration();
    LayerStack g = setupGenerator(MC_1_16);

    for (int64_t testSeed = 0; testSeed < 10; testSeed++) {
        Pos villagePos = getStructurePos(VILLAGE_CONFIG, testSeed, 0 , 0);
        Pos witchHutPos = getStructurePos(SWAMP_HUT_CONFIG, testSeed, 0, 0);
        Pos pyramidPos = getStructurePos(DESERT_PYRAMID_CONFIG, testSeed, 0, 0);
        Pos monumentPos = getLargeStructurePos(MONUMENT_CONFIG, testSeed, 0, 0);
        
        int64_t totalSeed = 0;
        int found = 0;
        int typesFound = 0x0;
        
        int64_t totalSeedMax = 0;
        int foundMax = 0;
        int typesFoundMax = 0;
        for (int64_t higherSeedBits = 0; found < 4 && higherSeedBits < (int)pow(2, 16); higherSeedBits++) {
            totalSeed = testSeed | (higherSeedBits<<48);
            applySeed(&g, totalSeed);
            found = 0;
            typesFound = 0;
            if (isViableVillagePos(g, NULL, villagePos.x, villagePos.z)) {
                found += 1;
                typesFound = typesFound | 1;
            }
            if (isViableFeaturePos(Swamp_Hut, g, NULL, witchHutPos.x, witchHutPos.z)) {
                found += 1;
                typesFound = typesFound | 2;
            }
            if (isViableFeaturePos(Desert_Pyramid, g, NULL, pyramidPos.x, pyramidPos.z)) {
                found += 1;
                typesFound = typesFound | 4;
            }
            if (isViableOceanMonumentPos(g, NULL, monumentPos.x, monumentPos.z)) {
                found += 1;
                typesFound = typesFound | 8;
            }
            if (found > foundMax) {
                foundMax = found;
                typesFoundMax = typesFound;
                totalSeedMax = totalSeed;
            }
        }
        printf("Best seed in structure seed %lld with %lld with configuration  %lld:%lld\n", testSeed, totalSeedMax, foundMax, typesFoundMax);
    }
    freeGenerator(g);
    return 0;
}
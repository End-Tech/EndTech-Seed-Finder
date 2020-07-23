#include "main.h"

int main() {

    initGeneration();
    LayerStack g = setupGenerator(MC_1_16);
    int64_t testSeed = 1; //easy to remember
    Pos villagePos = getStructurePos(VILLAGE_CONFIG, testSeed, 0 , 0);
    int found = 0;
    int64_t totalSeed = 0;
    for (int64_t higherSeedBits = 0;found < 1 && higherSeedBits < (int)pow(2, 16); higherSeedBits++) {
        totalSeed = testSeed | (higherSeedBits<<48);
        printf("searching %lld\n", totalSeed);
        applySeed(&g, totalSeed);
        if (isViableVillagePos(g, NULL, villagePos.x, villagePos.z)) {
            printf("found %lld\n", totalSeed);
        }
        if (getBiomeAtPos(g, villagePos)==snowy_tundra) {
            found++;
            printf("snowy tundra village at %lld\n", totalSeed);
        }
    }

    freeGenerator(g);
    return 0;
}
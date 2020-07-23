/*
    Generation functionality will be stored in this file
    It includes cubiomes which gives us access to many generation functions
    It then provides the additional stuff that we also need to generate to find out if our seed is the one we want.
*/


#include "cubiomes/finders.c"
#include "cubiomes/javarnd.h"
#include "math.h"
#include <limits.h>

#ifdef DEBUG
#define SEED -6463883208784934046 //6880093502557252720 //-6463883208784934046 Debug seed
#else
#define SEED 0 //Seed 0 is the lowest value the lower 48 bits can have
#endif
#define STRONGHOLD_DISTANCE 32
#define STRONGHOLD_SPREAD 3
#define STRONGHOLD_COUNT 128 //34 // Minecraft generates 128 strongholds spread into 8 rings around 0,0. We only care about the 4 first rings = 34 strongholds.
#define DOUBLE_UNIT 1.0 / (1L << 53)
#define PI 3.141592653589793

void initGeneration();
void getStrongholds(int64_t *seed, Pos *strongholds, LayerStack *g);

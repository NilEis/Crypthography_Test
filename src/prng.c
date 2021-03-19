#include "prng.h"
#include <stdint.h>

static uint32_t seed_lcg;

static const uint32_t modulus_lcg = 0x80000000; //2^31
static const uint32_t multiplier_lcg = 0x41C64E6D; //1103515245
static const uint32_t increment_lcg = 12345;


//Linear congruential generator
void lcg_seed(uint32_t seed)
{
    seed_lcg = seed;
}

uint32_t lcg_rand()
{
    seed_lcg = (multiplier_lcg * seed_lcg + increment_lcg) % modulus_lcg;
    return seed_lcg;
}

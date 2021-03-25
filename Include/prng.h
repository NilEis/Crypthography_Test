#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#ifndef PRNG_H_INCLUDED
#define PRNG_H_INCLUDED
#include <stdint.h>

void lcg_seed(uint32_t seed);
uint32_t lcg_rand();

#endif // PRNG_H_INCLUDED
#ifdef __cplusplus
}
#endif // __cplusplus

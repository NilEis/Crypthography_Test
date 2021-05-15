#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED
#include <stdint.h>

void get_RSA(uint32_t p,uint32_t q, uint32_t *ret_N, uint32_t *ret_e, uint32_t *ret_d);

#endif // RSA_H_INCLUDED
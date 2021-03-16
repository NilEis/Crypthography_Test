#include "asymmetric.h"

void get_RSA(int p,int q, int *ret_N, int *ret_e, int *ret_d)
{
    int N;
    int r;
    int e;
    int i;
    N = p*q;
    r = (p-1)*(q-1);
    e = 1;
    while((r%e)==0)
    {
        e++;
    }
    i = 1;
    while((i*r+1)%e!=0)
    {
        i++;
    }
    *ret_N = N;
    *ret_d = (i*r+1)/e;
    *ret_e = e;
    #if DEBUG
    printf("\nN:\n----------------------------------\n| N = p*q -> %d*%d = %d\n\n",p,q,*ret_N);
    printf("r:\n----------------------------------\n| r = (p-1)*(q-1) -> (%d-1)*(%d-1) = %d\n\n",p,q,r);
    printf("e:\n----------------------------------\n| r mod e != 0 -> %d mod %d = %d\n\n",r,*ret_e,(r%(*ret_e)));
    printf("d:\n----------------------------------\n| (e*d) mod r = 1 -> (%d*%d) mod %d = 1\n\n\n",*ret_e,*ret_d,r);
    printf("----------------------------------\n- p: %d\n- q: %d\n- N: %d\n- r: %d\n- e: %d\n- d: %d\n",p,q,*ret_N,r,*ret_e,*ret_d);
    printf("----------------------------------\npublic: (N: %d, e: %d)\nprivate: (N: %d, d: %d)\n",*ret_N,*ret_e,*ret_N,*ret_d);
    #endif // DEBUG
}

#include <stdio.h>
#include "helper_functions.h"
#include "asymmetric.h"

int main()
{
    int p = 0;
    int q = 0;
    int N = 0;
    int e = 0;
    int d = 0;
    int tested = 0;
    printf("Please input p and q: (p q):\n->");
    scanf("%d %d",&p,&q);
    tested = is_prime(p);
    if(tested==-1)
    {
        printf("p = %d is not a prime number\n", p);
        exit_program(-1);
    }
    tested = is_prime(q);
    if(tested==-1)
    {
        printf("q = %d is not a prime number\n", q);
        exit_program(-1);
    }
    get_RSA(p,q, &N, &e, &d);
    printf("\nN = %d\ne = %d\nd = %d\n\n",N,e,d);
    exit_program(0);
    return 0;
}

#include <stdio.h>
#include "main.h"

int main()
{
    int p,q;
    printf("Please input p and q: (p q):\n->");
    scanf("%d %d",&p,&q);
    //Flush input
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    if(test_prime(p)==-1)
    {
        printf("p = %d ist keine Primzahl\n", p);
        puts("Press ENTER to exit program");
        getchar();
        return -1;
    }
    if(test_prime(q)==-1)
    {
        printf("q = %d ist keine Primzahl\n", q);
        puts("Press ENTER to exit program");
        getchar();
        return -1;
    }
    getKeys(p,q);
    puts("Press ENTER to exit program");
    getchar();
    return 0;
}

void getKeys(int p,int q)
{
    int N = p*q;
    printf("\nN:\n----------------------------------\n| N = p*q -> %d*%d = %d\n\n",p,q,N);
    int r = (p-1)*(q-1);
    printf("r:\n----------------------------------\n| r = (p-1)*(q-1) -> (%d-1)*(%d-1) = %d\n\n",p,q,r);
    int e = 1;
    while((r%e)==0)
    {
        e++;
    }
    printf("e:\n----------------------------------\n| r mod e != 0 -> %d mod %d = %d\n\n",r,e,(r%e));
    /*while((e*d)%r!=1)
    {
        d++;
    }*/
    int i = 1;
    while((i*r+1)%e!=0)
    {
        i++;
    }
    int d = (i*r+1)/e;
    printf("d:\n----------------------------------\n| (e*d) mod r = 1 -> (%d*%d) mod %d = 1\n\n\n",e,d,r);
    printf("----------------------------------\n- p: %d\n- q: %d\n- N: %d\n- r: %d\n- e: %d\n- d: %d\n",p,q,N,r,e,d);
    printf("----------------------------------\npublic: (N: %d, e: %d)\nprivate: (N: %d, d: %d)\n",N,e,N,d);
}

int test_prime(int p)
{
    if(p>primes[primes_length-1])
    {
        return 1;
    }
    int l = 0;
    int r = primes_length-1;
    int m;
    while(l<=r)
    {
        m = (l + r) / 2;
        l = (primes[m]<p)*(m+1)+(primes[m]>p)*l;
        r = (primes[m]>p)*(m-1)+(primes[m]<p)*r;
        if(primes[m]==p)
        {
            return 0;
        }
    }
    return -1;
}

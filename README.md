# Test_RSA-Key-generator
Generates a key pair from two prime numbers and outputs the necessary calculations.

## Algorithm
1. Choose two prime numbers p and q
2. Calculate N = p*q
3. Calculate r = (p-1)*(q-1)
4. Choose e, where r mod e != 0

```C
int e = 1;
while((r%e)==0)
{
    e++;
}
```
5. Choose e, where (e\*d) mod r = 1
```C
int i = 1;
while((i*r+1)%e!=0)
{
    i++;
}
int d = (i*r+1)/e;
```
6. Publish N and e and keep d private

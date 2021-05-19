#include <lib.h>

int rand()
{
    static unsigned long int next = 1;
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % (RAND_MAX + 1);
}
 
unsigned randto(unsigned x)
{
    unsigned r, max = (RAND_MAX / x) * x;
    do
    {
        r = rand();
    }
    while (r >= max);
    return r % x;
}
 
unsigned rrand(unsigned min, unsigned max)
{
    return min + randto(max - min + 1);
}
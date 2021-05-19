#include <def.h>
#include <bool.h>

unsigned char memory[1024 * 1024];
size_t i = 0;

void *malloc(size_t size)
{
    void *mem;
    if (sizeof memory - i < size)
    {
        return FALSE;
    }
    mem = &memory[i];
    i += size;
    return mem;
}
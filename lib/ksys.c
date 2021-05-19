#include <io.h>

void reboot()
{
    inb(0x64);
    outb(0x64, 0xFE);
}

void shutdown()
{
    outw(0x604, 0x2000);
    outw(0x4004, 0x3400);
}